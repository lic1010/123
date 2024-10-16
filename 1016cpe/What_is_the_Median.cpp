#include <iostream>

using namespace std;

int main()
{
  int num[10000];
  int a = 0;
  int x;
  while( cin >> num[a] )
  {
    x = num[a];
    for(int i = 0 ; i <= a ; i++)
    {
      if( x <= num[i] )
      {
        for(int j = a+1 ; j > i;j--)
        {
          num[j] = num[j-1];
        }
        num[i] = x;
        break;
      }
    }
    if(a%2 ==0)
      cout<<num[a/2]<<endl;
    else
      cout<<(num[a/2]+num[a/2+1])/2<<endl;
    a++;
  }
  return 0;
}