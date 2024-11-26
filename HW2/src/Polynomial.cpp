#include<iostream>
#include <cmath>//用在Eval()的計算
using namespace std;
class polynomial ;
class Term {
    friend polynomial;
    float coe;
    int exp;
public:// 不可以直接使用coe和exp
    float getcoe(){return coe;} //用函式來給予
    int getexp(){return exp;}
};
class polynomial {
private:
    Term *termArray;
    int capacity; // 容量
    int terms; // 項目數量
public:
    polynomial(int box = 10); // 新增位子
    ~polynomial(); // 歸還位子
    polynomial(polynomial &poly); //複製建構函數
    polynomial Add(polynomial poly); // 加法
    polynomial Mult(polynomial poly); // 乘法
    void newA(float coe,int exp);//存放資料和擴建box
    friend ostream& operator<<(ostream& output, polynomial& p);
    friend istream& operator>>(istream& input, polynomial& p);
    float Eval(float f);
};
polynomial::polynomial(int box):capacity(box),terms(0) {
    termArray=new Term[box];
}
polynomial::~polynomial() {
    delete []termArray;//解構
}
void polynomial::newA(float coe, int exp) {//增加空間
    if(capacity==terms) {
        capacity*=2;//空間增加*2
        Term *newA=new Term[capacity];
        for(int i=0;i<terms;i++) {
            newA[i]=termArray[i];
        }
        delete []termArray; //把指標的值歸還
        termArray=newA;//指向新陣列
    }
    termArray[terms].coe=coe;//存入係數
    termArray[terms].exp=exp;//存入指數
    terms++;
}
polynomial::polynomial(polynomial &poly) {
    termArray = new Term[poly.capacity];
    for(int a=0;a<poly.terms;a++)termArray[a]=poly.termArray[a];
    capacity=poly.capacity;
    terms=poly.terms;
}

polynomial polynomial::Add(polynomial poly) {
        polynomial result;
    int i = 0, j = 0;
    while (i < terms && j < poly.terms) {
        if (termArray[i].exp == poly.termArray[j].exp) {//指數一樣
            float sumCoef = termArray[i].coe + poly.termArray[j].coe;
            if (sumCoef != 0) result.newA(sumCoef, termArray[i].exp);//相加傳入到newA()裡面存放
            i++;
            j++;
        } else if (termArray[i].exp > poly.termArray[j].exp) {//大於傳入到newA()裡面存放
            result.newA(termArray[i].coe, termArray[i].exp);
            i++;
        } else {//小於傳入到newA()裡面存放
            result.newA(poly.termArray[j].coe, poly.termArray[j].exp);
            j++;
        }
    }
    while (i < terms) {//剩下的值存到newA()裡面存放
        result.newA(termArray[i].coe, termArray[i].exp);
        i++;
    }
    while (j < poly.terms) {//剩下的值存到newA()裡面存放
        result.newA(poly.termArray[j].coe, poly.termArray[j].exp);
        j++;
    }
    return result;
}

polynomial polynomial::Mult(polynomial poly) {
    polynomial result;
    for (int i = 0; i < terms; i++) {
        for (int j = 0; j < poly.terms; j++) {
            double newCoef = termArray[i].coe * poly.termArray[j].coe;
            int newExp = termArray[i].exp + poly.termArray[j].exp;

            bool found = false; //檢查有沒有相同，如果有加並不要存到裡面
            for (int k = 0; k < result.terms; k++) {
                if (result.termArray[k].exp == newExp) {
                    result.termArray[k].coe += newCoef;
                    found = true;
                    break;
                }
            }
            if (!found) result.newA(newCoef, newExp);//沒有重複的值
        }
    }
    return result;
}

float polynomial::Eval(float x)  {
    double result = 0.0;
    for (int i = 0; i < terms; i++) {
        result += termArray[i].coe * pow(x, termArray[i].exp);//算輸多項式的值
    }
    return result;
}

ostream& operator<<(ostream& output, polynomial& poly) {
        for (int i = 0; i < poly.terms; i++) {
            if (i > 0 && poly.termArray[i].getcoe() > 0) output << "+";//後一個不會有+
            output << poly.termArray[i].getcoe() << "x^" << poly.termArray[i].getexp();
        }
    return output;
}


istream& operator>>(istream& input, polynomial& poly) {
    int termCount;
    cout << "請輸入多項式的項數:";
    input >> termCount;
    for (int i = 0; i < termCount; i++) {//一個一個存
        double coef;
        int exp;
        cout << "請輸入係數與指數（如 2 3 表示 2x^3）：";
        input >> coef >> exp;
        poly.newA(coef, exp); //新增到陣列
    }
    return input;
}

int main() {
    polynomial p1, p2;
    cout << "第一個多項式" << endl;
    cin >> p1;
    cout << "第二個多項式" << endl;
    cin >> p2;
    cout << "第一個多項式：" << p1 << endl;
    cout << "第二個多項式：" << p2 << endl;
    polynomial sum = p1.Add(p2);
    cout << "兩多項式相加結果：" << sum << endl;
    polynomial product = p1.Mult(p2);
    cout << "兩多項式相乘結果：" << product << endl;
    double x;
    cout << "請輸入 x 的值以計算多項式值：";
    cin >> x;
    cout << "第一個多項式在 x = " << x << " 的值為：" << p1.Eval(x) << endl;
    cout << "第二個多項式在 x = " << x << " 的值為：" << p2.Eval(x) << endl;
    return 0;
}
