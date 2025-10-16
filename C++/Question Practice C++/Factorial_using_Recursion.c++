#include<iostream>
using namespace std;

int Factorial(int n){
    if (n == 0 || n == 1) return 1;
    else return n * Factorial(n-1);
}

int main(){
    int num;

    cout<<"Enter the Number: ";
    cin>>num;

    int fact = Factorial(num);
    cout<<"Factorial is "<<fact<<endl;
    
    return 0;
}