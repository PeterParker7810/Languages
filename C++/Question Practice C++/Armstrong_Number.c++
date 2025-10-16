#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int num, power = 0;

    cout<<"Enter the number: ";
    cin>>num;

    int check = num;
    int sum = 0;

    while (num != 0){
        num /= 10;
        power++;
    }

    int check1 = check;

    while (check != 0){
        sum += pow(check%10,power);
        check /= 10;
    }

    if (check1 == sum){
        cout<<"Yes..."<<check1<<" is an Armstrong Number";
    }
    else{
        cout<<"No..."<<check1<<" is not an Armstrong Number";
    }

    return 0;
}
