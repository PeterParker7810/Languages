#include<stdio.h>

int main(){
    int limit;    
    printf("Enter the limit: ");
    scanf("%d",&limit);

    //Pattern-1
    printf("\nPattern-1:\n");
    for (int i = 0; i < limit; i++){
        for (int j = 0; j <= i; j++){
            printf("* ");
        }
        printf("\n");
    }

    //Pattern-2
    printf("\nPattern-2:\n");
    for (int i = 0; i < limit; i++){
        for (int j = 0; j <= i; j++){
            printf("  ");
        }
        for (int k = limit; k > i; k--){
            printf("* ");
        }
        printf("\n");
    }

    //Pattern-3
    printf("\nPattern-3:\n");
    for (int i = limit; i > 0; i--){
        for (int j = 0; j < i; j++){
            printf("* ");
        }
        printf("\n");
    }

    //Pattern-4
    printf("\nPattern-4:\n");
    for (int i = limit; i > 0; i--){
        for (int j = 1; j < i; j++){
            printf("  ");
        }
        for (int k = limit; k >= i; k--){
            printf("* ");
        }
        printf("\n");
    }   
    //Pattern-5
    printf("\nPattern-5:\n");
    for (int i = 0; i < limit; i++){
        for (int j = 0; j <= i; j++){
            printf("* ");
        }
        printf("\n");
    }
    for (int i = limit; i > 0; i--){
        for (int j = 1; j < i; j++){
            printf("* ");
        }
        printf("\n");
    }

    //Pattern-6
    printf("Pattern-6:\n");
    for (int i = limit; i > 0; i--){
        for (int j = 1; j < i; j++){
            printf("  ");
        }
        for (int k = limit; k >= i; k--){
            printf("* ");
        }
        printf("\n");
    }
    for (int i = 0; i < limit; i++){
        for (int j = 0; j <= i; j++){
            printf("  ");
        }
        for (int k = limit-1; k > i; k--){
            printf("* ");
        }
        printf("\n");
    }

    //Pattern-7
    printf("\nPattern-7:\n");
    for (int i = limit; i > 0; i--){
        for (int j = 1; j < i; j++){
            printf(" ");
        }
        for (int k = limit; k >= i; k--){
            printf("* ");
        }
        printf("\n");
    }
    for (int i = 0; i < limit; i++){
        for (int j = 0; j <= i; j++){
            printf(" ");
        }
        for (int k = limit-1; k > i; k--){
            printf("* ");
        }
        printf("\n");
    }

    //Pattern-8
    printf("\nPattern-8:\n");
    int temp = 1;
    for (int i = 1; i <= limit*2; i++){
        if (i%2 == 0){
            for (int j = limit*2; j >= i; j--){
                printf(" ");
            }
        }
        else{
            for (int j = limit*2; j > i; j--){
                printf(" ");
            }
        }

        for (int k = 1; k <= temp; k++){
            printf("* ");
        }
        printf("\n");
        if (i%2 == 0){
            temp += 2;
        }
    }

    //Pattern-9
    printf("\nPattern-9:\n");
    for (int i = 0; i < limit-1; i++){
        for (int j = 1; j <= i; j++){
            printf(" ");
        }
        for (int k = limit; k > i; k--){
            printf("* ");
        }
        printf("\n");
    }
    for (int i = limit; i > 0; i--){
        for (int j = 1; j < i; j++){
            printf(" ");
        }
        for (int k = limit; k >= i; k--){
            printf("* ");
        }
        printf("\n");
    }

    //Pattern-10
    printf("\nPattern-10:\n");
    for (int i = limit; i > 0; i--){
        for (int j = 1; j < i; j++){
            printf(" ");
        }
        for (int k = limit; k >= i; k--){
            if (k == limit || k == i){
                printf("* ");
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }
    for (int i = 0; i < limit; i++){
        for (int j = 0; j <= i; j++){
            printf(" ");
        }
        for (int k = limit-1; k > i; k--){
            if (k == limit-1 || k == i+1){
                printf("* ");
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }

    //Pattern-11
    printf("Pattern-11:\n");
    for (int i = 0; i < limit; i++){
        for (int j = 0; j < limit; j++){
            if (i == 0 || i == limit-1){
                printf("* ");
            }
            else{
                if (j == 0 || j == limit-1){
                    printf("* ");
                }
                else{
                    printf("  ");
                }
            }
        }
        printf("\n");
    }

    //Pattern-12
    printf("\nPattern-12:\n");
    for (int i = limit; i > 0; i--){
        for (int j = 1; j < i; j++){
            printf(" ");
        }
        for (int k = limit; k >= i; k--){
            if (i == 1){
                printf("* ");
            }
            else{
                if (k == limit || k == i){
                    printf("* ");
                }
                else{
                    printf("  ");
                }
            }
        }
        printf("\n");
    }

    //Pattern-13
    printf("\nPattern-13:\n");
    for (int i = 0; i < limit; i++){
        for (int j = 0; j <= i; j++){
            printf(" ");
        }
        for (int k = limit; k > i; k--){
            if (i == 0){
                printf("* ");
            }
            else{
                if (k == limit || k == i+1){
                    printf("* ");
                }
                else{
                    printf("  ");
                }
            }
        }
        printf("\n");
    }

    //Pattern-14
    printf("\nPattern-14:\n");
    for (int i = 0; i < limit; i++){
        for (int j = 1; j <= i; j++){
            printf("  ");
        }
        for (int k = 0; k < limit; k++){
            printf("* ");
        }
        printf("\n");
    }

    //Pattern-15
    printf("\nPattern-15:\n");
    for (int i = 0; i < limit-1; i++){
        for (int j = 1; j <= i; j++){
            printf(" ");
        }
        for (int k = limit; k > i; k--){
            if (i == 0){
                printf("* ");
            }
            else{
                if (k == limit || k == i+1){
                    printf("* ");
                }
                else{
                    printf("  ");
                }
            }
        }
        printf("\n");
    }
    for (int i = limit; i > 0; i--){
        for (int j = 1; j < i; j++){
            printf(" ");
        }
        for (int k = limit; k >= i; k--){
            if (i == 1){
                printf("* ");
            }
            else{
                if (k == limit || k == i){
                    printf("* ");
                }
                else{
                    printf("  ");
                }
            }
        }
        printf("\n");
    }

    return 0;
}