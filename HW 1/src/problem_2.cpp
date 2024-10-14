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
void fun(int size_fun,int b[],int inex) {
    int a[4];
    if (inex==pow(2,size_fun)) return;
        cout<<"(";
        two(inex,a);
        bool c=true;
        for(int j=0;j<size_fun;j++) {
            if(a[j]==1) {
                if(!c) {
                    cout<<",";
                }
                cout<<b[j];
                c=false;
            }
        }
        cout<<")";
        if(inex<pow(2,size_fun)-1)
        cout<<", ";
        fun(size_fun,b,inex+1);
    }

int main() {
    int b[3]={1,2,3};
    cout<<"S={";
    fun(3,b,0);
    cout<<"}";


    return 0;
}
