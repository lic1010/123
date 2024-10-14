#include<iostream>
#include<cmath>
#include<vector>
class
using namespace std;
int f(int m,int n) {
    if(m==0) return n+1;
    if(n==0) return f(m-1,1);
    return f(m-1,f(m,n-1));
}


int ack(int m, int n) {
        if(m==0) {
            return n+1;
        }
        else if(m==1) {
            return n+2;
        }
        else if(m==2) {
            return 2*(n+3)-3;
        }
        else if(m==3) {
            return pow(2,n+3)-3;
        }
        else {
            return -1;
        }
    }
int main() {
    int x=ack(3,0);
    cout<< f(3,0)<<endl;
    if(x==-1)
        cout<< "輸出數值過大，請重試";
    else {
        cout<<x;
    }
    return 0;
}
