#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int f(int m,int n) {
    if(m==0) return n+1;
    if(n==0) return f(m-1,1);
    return f(m-1,f(m,n-1));
}

int ack(int m, int n) {
        vector<int> stack;
        stack.push_back(m);
        while (!stack.empty()) {
            m = stack.back();
            stack.pop_back();

            if (m == 0) {
                n += 1;
            } else if (n == 0) {
                n = 1;
                stack.push_back(m - 1);
            } else {
                stack.push_back(m - 1);
                stack.push_back(m);
                n -= 1;
            }
        }
        return n;
    }
int main() {
    cout<< f(4,0)<<endl;
    cout<< ack(4,0);
    return 0;
}
