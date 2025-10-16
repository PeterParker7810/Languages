#include<stdio.h>
#include<string.h>
#include<math.h>

int main(){
    int num;
    char ntype[10];

    printf("Enter the number type (Binary or Decimal): ");
    scanf("%s",&ntype);

    if (strcmp(ntype,"binary") == 0){
        printf("Enter the number: ");
        scanf("%d",&num);

        int ans = 0, limit = 0;
        int num1 = num;

        while (num != 0){
            num /= 10;
            limit++;
        }

        for (int i = 0; i < limit; i++){
            ans += pow(2,i)*(num1%10);
            num1 /= 10;
        }

        printf("Number in Decimal is %d",ans);
    }

    else if (strcmp(ntype,"decimal") == 0){
        printf("Enter the number: ");
        scanf("%d",&num);

        int arr[100], index = 0;

        printf("Number in Binary is ");
        while (num != 1){
            arr[index] = num%2;
            num /= 2;
            index++;
            if (num == 1){
                arr[index] = num;
            }
        }

        for (int i = index; i >= 0; i--){
            printf("%d",arr[i]);
        }

    }

    else{
        printf("Didn't get that....");
    }
    
    return 0;
}