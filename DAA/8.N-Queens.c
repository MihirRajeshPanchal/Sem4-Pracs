#include<stdio.h>
#include<stdbool.h>
#include<math.h>

#define N 20

int board[N][N];
int count = 0;

void printSolution(int n);
bool isSafe(int row, int col, int n);
bool solveNQueensUtil(int col, int n);
bool solveNQueens(int n);

int main() {
    int n;
    printf("Enter number of Queens : ");
    scanf("%d", &n);
    if (solveNQueens(n))
        printf("\nTotal solutions: %d\n", count);
    else
        printf("\nNo solution exists for %d queens.\n", n);
    return 0;
}

void printSolution(int n) {
    int i, j;
    printf("\n\nSolution : %d\n\n", ++count);
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            if (board[i][j] == 1)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

bool isSafe(int row, int col, int n) {
    int i, j;
    for (i = 0; i < col; i++) {
        if (board[row][i])
            return false;
    }
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return false;
    }
    for (i = row, j = col; j >= 0 && i < n; i++, j--) {
        if (board[i][j])
            return false;
    }
    return true;
}

bool solveNQueensUtil(int col, int n) {
    if (col == n) {
        printSolution(n);
        return true;
    }
    bool res = false;
    for (int i = 0; i < n; i++) {
        if (isSafe(i, col, n)) {
            board[i][col] = 1;
            res = solveNQueensUtil(col + 1, n) || res;
            board[i][col] = 0;
        }
    }
    return res;
}

bool solveNQueens(int n) {
    if (n <= 0 || n > N) {
        printf("Invalid input.\n");
        return false;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }
    return solveNQueensUtil(0, n);
}