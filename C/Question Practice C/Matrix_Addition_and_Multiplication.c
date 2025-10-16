#include<stdio.h>

int main(){
    int m1,n1;

    printf("For Matrix-1:\n");
    printf("Enter number of Columns(m): ");
    scanf("%d",&m1);

    printf("Enter number of Rows(n): ");
    scanf("%d",&n1);

    int m2,n2;

    printf("\nFor Matrix-2:\n");
    printf("Enter number of Columns(m): ");
    scanf("%d",&m2);

    printf("Enter number of Rows(n): ");
    scanf("%d",&n2);

    //Values for Matrices
    int matrix1[100][100],matrix2[100][100];

    printf("\nValues for Matrix-1:\n");
    for (int i = 0; i < m1; i++){
        for (int j = 0; j < n1; j++){
            printf("Enter m%d%d: ",i+1,j+1);
            scanf("%d",&matrix1[i][j]);
        }
    }

    printf("\nValues for Matrix-2:\n");
    for (int i = 0; i < m2; i++){
        for (int j = 0; j < n2; j++){
            printf("Enter m%d%d: ",i+1,j+1);
            scanf("%d",&matrix2[i][j]);
        }
    }

    //Printing Matrices
    printf("\nMatrix-1:\n");
    for (int i = 0; i < m1; i++){
        for (int j = 0; j < n1; j++){
            printf("%d ",matrix1[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix-2:\n");
    for (int i = 0; i < m2; i++){
        for (int j = 0; j < n2; j++){
            printf("%d ",matrix2[i][j]);
        }
        printf("\n");
    }

    //Adding Matrices
    if (m1 == m2 && n1 == n2){
        printf("\nMatrix-1 + Matrix-2:\n");
        for (int i = 0; i < m2; i++){
            for (int j = 0; j < n2; j++){
                printf("%d ",matrix1[i][j]+matrix2[i][j]);
            }
            printf("\n");
        }
    }

    else{
        printf("\nThe Above Matrices cannot be added\n");
    }

    //Multiplying Matrices
    if (n1 == m2){
        int matrix3[100][100];
        printf("\nMatrix-1 * Matrix-2:\n");
        for (int i = 0; i <= n1; i++){
            for (int j = 0; j <= n1; j++){
                for (int k = 0; k <= n1; k++){
                    matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }

        for (int i = 0; i < m1; i++){
            for (int j = 0; j < n2; j++){
                printf("%d ",matrix3[i][j]);
            }
            printf("\n");
        }

    }

    else{
        printf("\nThe Above Matrices cannot be multiplied");
    }

    return 0;
}
