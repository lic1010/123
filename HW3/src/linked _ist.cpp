#include<iostream>
#include <cmath>
using namespace std;
class Node{
  public:
    float coef;
    int exp;
    Node *link;//指向下一個位子
};
class Polynomial {
private:
  Node *hand;
public:
  Polynomial();//建構值
  ~Polynomial();//解構值
  Polynomial(const Polynomial& a);//複製建構值
  void Added(float coef,int exp);//新增函數
  Polynomial &operator=(const Polynomial &a);//等號
  Polynomial operator+(const Polynomial &b);//加法
  Polynomial operator-(const Polynomial &b);//減法
  Polynomial operator*(const Polynomial &b);//乘法
  float Eval(float x)const;//給值代入
  friend ostream& operator<<(ostream& os, const Polynomial& b);
  friend istream& operator>>(istream& is, Polynomial& b);
};
Polynomial::Polynomial() {
  hand=new Node{0,0 ,NULL};
  hand->link=hand;
}
Polynomial::~Polynomial() {
  Node* curr = hand->link;
  while (curr != hand) {//一個一個解構
    Node* temp = curr;
    curr = curr->link;
    delete temp;
  }
  hand->link = hand;
  delete hand;//最後解頭
}
Polynomial::Polynomial(const Polynomial &a) {
  hand=new Node{0,-1,NULL};
  hand->link=hand;
  Node *cu=a.hand->link;
  while(cu!=a.hand) {
    Added(cu->coef,cu->exp);
    cu=cu->link;
  }
}

void Polynomial::Added(float coef, int exp) {
  Node* prev = hand;//下一個
  Node* curr = hand->link;//目前
  while (curr != hand && curr->exp > exp) {//看要新增哪裡位子
    prev = curr;
    curr = curr->link;
  }
    Node* newTerm = new Node{coef, exp, curr};//建立新的節點(1個)
    prev->link = newTerm;//插入
}
Polynomial &Polynomial::operator=(const Polynomial &a) {
  if (this != &a) {//要先把等號左邊的值全部消除
    Node* d = hand->link;
    while (d != hand) {
      Node *t = d;
      d = d->link;
      delete t;
    }
    hand->link = hand;

    Node* cu = a.hand->link;
    while (cu != a.hand) {//放入值
      Added(cu->coef, cu->exp);
      cu = cu->link;
    }
  }
  return *this;
}
Polynomial Polynomial::operator+(const Polynomial &b) {
  Polynomial result;
  Node *a1=hand->link;//自己
  Node *b1=b.hand->link;//被加
  while(a1!=hand||b1!=b.hand) {
    if(a1->exp > b1->exp) {//a1比較大放入result
      result.Added(a1->coef,a1->exp);
      a1=a1->link;//在指向下一個
    }
    else if(a1->exp < b1->exp) {//b1比較大放入result
      result.Added(b1->coef,b1->exp);
      b1=b1->link;//在指向下一個
    }
    else {//指數相同相加完放入result，在兩個指標往下走
      result.Added(a1->coef+b1->coef,a1->exp);
      a1=a1->link;
      b1=b1->link;
    }
  }
  return result;
}
Polynomial Polynomial::operator-(const Polynomial &b) {
  Polynomial result;
  Node *a1=hand->link;//自己
  Node *b1=b.hand->link;//被減
  while(a1!=hand||b1!=b.hand) {
    if(a1->exp>b1->exp) {//a1比較大放入result
      result.Added(a1->coef,a1->exp);
      a1=a1->link;//在指向下一個
    }
    else if(a1->exp<b1->exp) {//b1比較大放入result
      result.Added(-b1->coef,b1->exp);
      b1=b1->link;//在指向下一個
    }
    else {//指數相同相減完放入result，在兩個指標往下走
      result.Added(a1->coef - b1->coef,a1->exp);
      a1=a1->link;
      b1=b1->link;
    }
  }
  return result;
}
Polynomial Polynomial::operator*(const Polynomial &b) {
  Polynomial result;
  Node *a1=hand->link;//自己
  while (a1!=hand) {//利用氣泡排序法
    Node *b1=b.hand->link;//被乘
    while(b1!=b.hand) {
      Node *r=result.hand->link;//檢查有沒有重複的指標
      float newcoef=a1->coef*b1->coef;
      int newexp=a1->exp+b1->exp;
      bool t=false;
      while(r!=result.hand) {//檢查有沒有重複
        if(r->exp==newexp) {
          r->coef+=newcoef;
          t=true;
          break;
        }
        r=r->link;
      }
      if(!t) result.Added(newcoef,newexp);//沒有重複放入result中
      b1=b1->link;
    }
    a1=a1->link;
  }
  return result;
}
float Polynomial::Eval(float x) const {
  float result=0.0;
  Node* r=hand->link;
  while (r!=hand) {
    result+=r->coef*pow(x,r->exp);
    r=r->link;
  }
  return result;
}
ostream& operator<<(ostream& output, const Polynomial& b) {
  Node* curr = b.hand->link;
  bool first = true;
  while (curr != b.hand) {
    if (!first && curr->coef > 0) output << "+";//後一個不會有+
    output << curr->coef << "x^" << curr->exp;
    curr = curr->link;
    first = false;
  }
  return output;
}

istream& operator>>(istream& input, Polynomial& b) {
  int num;
  cout << "請輸入有幾項指數: ";
  input >> num;
  for (int i = 0; i < num; i++) {//一個一個存
    cout << "請輸入系數與指數(ex:2 3->2x^3): ";
    int exp;
    float coef;
    input >> coef >> exp;
    b.Added(coef, exp);//新增
  }
  return input;
}

int main(){
  Polynomial p1,p2;
  cout<<"請輸入第一項多項式\n";
  cin>>p1;
  cout<<"請輸入第二項多項式\n";
  cin>>p2;
  cout<<"p1:"<<p1<<endl;
  cout<<"p2:"<<p2<<endl;
  Polynomial sum=p1+p2;
  cout<<"p1+p2="<<sum<<endl;
  Polynomial di=p1-p2;
  cout<<"p1-p2="<<di<<endl;
  Polynomial pr=p1*p2;
  cout<<"p1*p2="<<pr<<endl;
  float x;
  cout<<"請輸入要代入多項式的X=";
  cin>>x;
  cout<<"p1代入x="<<x<<"共"<<p1.Eval(x)<<endl;
  cout<<"p2代入x="<<x<<"共"<<p2.Eval(x)<<endl;

  return 0;
}