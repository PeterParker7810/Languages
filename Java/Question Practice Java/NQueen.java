import java.util.Scanner;
public class NQueen{
    public static boolean isSafe(int[][] board, int row, int col, int N) {
        for (int i = 0; i < row; i++) if (board[i][col] == 1) return false;

        for (int i = 0; i < row; i++) for (int j = 0; j < N; j++) {
            if (Math.abs(i - row) == Math.abs(j - col) && board[i][j] == 1) return false;
        }

        return true;
    }

    public static void NQueen(int[][] board, int row, int[] solutions, int N) {
        if (row == N) {
            solutions[0]++;
            return;
        }
        for (int col = 0; col < N; col++) {
            if (isSafe(board, row, col, N)) {
                // Place queen
                board[row][col] = 1;

                // Move to the next row
                NQueen(board, row + 1, solutions, N);

                // Remove queen (backtrack)
                board[row][col] = 0;
            }
        }
    }
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);

        System.out.print("Enter the value of N: ");
        int N = input.nextInt();
        int[] solutions = new int[1];

        int[][] board = new int[N][N];
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) board[i][j] = 0;

        NQueen(board, 0, solutions, N);
        System.out.println("Total solutions for " + N + "-Queens: " + solutions[0]);
    }
}