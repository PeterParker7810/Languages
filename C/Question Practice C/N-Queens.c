#include<stdio.h>

int isSafe(int N, int board[20][20], int row, int col){
    for (int i = 0; i < row; i++) if (board[i][col]) return 0;

    for (int i = 0; i < row; i++) for (int j = 0; j < N; j++) {
        if (((i+j == row+col) || (i-j == row-col)) && board[i][j]) return 0;
    }

    return 1;
}

void NQueen(int N, int board[20][20], int row, int* solutions){
    if (row == N) {
        (*solutions)++;
        return;
    }

    for (int col = 0; col < N; col++){
        if (isSafe(N, board, row, col)){
            // Place Queen
            board[row][col] = 1;

            // Move to next row
            NQueen(N, board, row + 1, solutions);
            
            // Remove Queen
            board[row][col] = 0;
        }
    }
}

int main(){
    int N, solutions = 0;
    printf("Enter the value of N: ");
    scanf("%d", &N);

    int board[20][20];
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) board[i][j] = 0;

    NQueen(N, board, 0, &solutions);
    printf("Total solutions for %d-Queens: %d\n", N, solutions);
    
    return 0;
}