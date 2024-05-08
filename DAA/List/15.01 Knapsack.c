#include<stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int capacity, int weight[], int profit[], int n) {
    int i, j;
    int K[n + 1][capacity + 1];
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= capacity; j++) {
            if (i == 0 || j == 0)
                K[i][j] = 0;
            else if (weight[i - 1] <= j)
                K[i][j] = max(profit[i - 1] + K[i - 1][j - weight[i - 1]], K[i - 1][j]);
            else
                K[i][j] = K[i - 1][j];
        }
    }
    for(int i=0; i <= n; i++){
        for(int j = 0; j <= capacity; j++){
            printf("%d ", K[i][j]);
        }
        printf("\n");
    }
    
    return K[n][capacity];
}

int main() {
    int profit[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int capacity = 50;
    int n = sizeof(profit) / sizeof(profit[0]);
    printf("Maximum profit is : %d\n", knapsack(capacity, weight, profit, n));
    return 0;
}
