#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    for (int i = 0; i < row; i++) if (board[i][col]) return false;

    for (int i = 0; i < row; i++) {          
        for (int j = 0; j < n; j++) {        
            if (board[i][j]) if (abs(i - row) == abs(j - col)) return false;
        }
    }

    return true; 
}


void NQueen(vector<vector<int>>& board, int row, int& solutions, int n) {
    if (row == n) {
        solutions++;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            // Place queen
            board[row][col] = 1;

            // Move to next row
            NQueen(board, row + 1, solutions, n);

            // Backtrack (remove queen)
            board[row][col] = 0;
        }
    }
}

int main() {
    int N, solutions = 0;
    cout<<"Enter the value of N: ";
    cin>>N;

    vector<vector<int>> board(N, vector<int>(N, 0));

    NQueen(board, 0, solutions, N);
    cout<<"Number of possible solutions for "<<N<<"-Queens is: "<<solutions<<endl;

    return 0;
}
