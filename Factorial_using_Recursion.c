#include<stdio.h>

int Factorial(int n){
    if (n == 0 || n == 1) return 1;
    else return n * Factorial(n-1);
}

int main(){
    int num;

    printf("Enter the Number: ");
    scanf("%d", &num);

    int fact = Factorial(num);
    printf("Factorial is %d", fact);

    return 0;
}