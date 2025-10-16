#include<stdio.h>

int Fibonacci(int lim){
    if (lim <=1) return lim;
    else return Fibonacci(lim-1) + Fibonacci(lim-2);
}

int main(){
    int limit;
    printf("Enter the Limit: ");
    scanf("%d", &limit);

    printf("Fibonacci Series: ");
    for (int i = 0; i < limit; i++) printf("%d ", Fibonacci(i));
    
    return 0;
}