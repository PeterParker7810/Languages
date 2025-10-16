#include<stdio.h>
#include<math.h>

int main(){
    int num, power = 0, sum = 0;
    printf("Enter the number: ");
    scanf("%d",&num);

    int check = num;
    while (num != 0){
        num /= 10;
        power++;
    }

    int check1 = check;
    while (check != 0){
        sum += pow(check%10,power);
        check /= 10;
    }

    if (check1 == sum) printf("Yes...%d is an Armstrong Number", check1);
    else printf("No...%d is not an Armstrong Number", check1);

    return 0;
}