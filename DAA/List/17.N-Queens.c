#include <stdio.h>
#include <conio.h>
#include <math.h>

#define MAX_N 30

int queens[MAX_N], solution_count = 0;

int isSafe(int row, int col) {
    for (int i = 1; i < row; i++) {
        if (queens[i] == col || abs(queens[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}

void printSolution(int n) {
    solution_count++;
    printf("\n\nSolution #%d:\n", solution_count);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (queens[i] == j)
                printf("Q\t");
            else
                printf("*\t");
        }
        printf("\n");
    }
}

void placeQueens(int n) {
    int row = 1;
    queens[row] = 0;
    while (row != 0) {
        queens[row]++;
        while ((queens[row] <= n) && !isSafe(row, queens[row]))
            queens[row]++;
        if (queens[row] <= n) {
            if (row == n)
                printSolution(n);
            else {
                row++;
                queens[row] = 0;
            }
        }
        else
            row--;
    }
}

int main() {
    int n;
    printf("Enter the number of Queens\n");
    scanf("%d", &n);
    placeQueens(n);
    printf("\nTotal solutions=%d", solution_count);
    return 0;
}
