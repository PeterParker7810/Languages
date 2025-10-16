#include<iostream>
using namespace std;

int Factorial(int num){
    if(num <= 1) return 1;
    else return num * Factorial(num - 1);
}

int main(){
    int num;
    cout<<"Enter the Number: ";
    cin>>num;

    int fact = Factorial(num);
    cout<<"Factorial is "<<fact;
    
    return 0;
}
