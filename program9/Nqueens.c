#include <stdio.h>

#define MAX 10

int board[MAX], count = 0;

// Function to check whether queen can be placed safely
int isSafe(int row, int col) {
    for (int i = 1; i < row; i++) {

        // Check same column
        if (board[i] == col)
            return 0;

        // Check diagonal
        if ((i - row) == (board[i] - col) ||
            (i - row) == (col - board[i]))
            return 0;
    }

    return 1;
}

// Function to print solution
void printSolution(int n) {
    printf("\nSolution %d:\n", ++count);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {

            if (board[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

// N-Queens function using backtracking
void NQueens(int row, int n) {

    for (int col = 1; col <= n; col++) {

        // Place queen
        board[row] = col;

        // Check if safe
        if (isSafe(row, col)) {

            // If all queens placed
            if (row == n) {
                printSolution(n);
            }
            else {
                // Recur for next row
                NQueens(row + 1, n);
            }
        }

        // Backtrack
        board[row] = 0;
    }
}

int main() {
    int n;

    printf("Enter number of queens: ");
    scanf("%d", &n);

    NQueens(1, n);

    if (count == 0) {
        printf("No solutions found.\n");
    }

    return 0;
}
