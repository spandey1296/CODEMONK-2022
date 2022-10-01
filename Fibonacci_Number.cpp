// Name: SARAVANAN S
// Github id: sarav18302

#include<bits/stdc++.h>
using namespace std;
int fib(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        
        return fib(n-1)+fib(n-2);
    }
    
int main()
{
int n;
cout<<"Enter any number";
cin>>n;
cout<<"nth Term of the Fibonacci is"<<fib(n);
return 0;
}
