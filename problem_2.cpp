#include<iostream>
#include<cmath>
using namespace std;
void  two(int x,int a[]) {// 十轉二
    int i=0;
    while(x!=0) {
        a[i]=x%2;
        x=x/2;
        i++;
    }
}
void fun(int size_fun,int b[]) {
    int a[4];
    for(int i=0;i<pow(2,size_fun);i++) {
        two(i,a);
        for(int j=0;j<size_fun;j++) {
            if(a[j]==1) {
                cout<<b[j];
            }
        }
        cout<<'\n';
    }
}

int main() {
    int b[3]={1,2,3};
    fun(3,b);


    return 0;
}
