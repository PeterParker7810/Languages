#include<iostream>
using namespace std;

int Fibonacci(int lim){
    if (lim <= 1) return lim;
    else return Fibonacci(lim-1) + Fibonacci(lim-2);
}

int main(){
    int limit;
    cout<<"Enter the Limit: ";
    cin>>limit;

    cout<<"Fibonacci Series: ";
    for(int i=0; i<limit; i++) cout<<Fibonacci(i)<<" ";

    return 0;
}