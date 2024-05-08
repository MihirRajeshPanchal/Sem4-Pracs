#include <stdio.h>

#define max 50

int subset[max];
int elements[max];
int target;
int n;

void findSumofSubet(int index, int current_sum, int remaining_sum) {
    if (current_sum == target) {
        for (int i = 0; i < n; i++) {
            printf("%d", subset[i]);
        }
        printf("\n");
        return;
    }
    
    if (index == n || current_sum > target || current_sum + remaining_sum < target) {
        return;
    }

    subset[index] = 1;
    findSumofSubet(index + 1, current_sum + elements[index], remaining_sum - elements[index]);

    subset[index] = 0;
    findSumofSubet(index + 1, current_sum, remaining_sum - elements[index]);
}

int main() {
    printf("Enter Number of Elements : ");
    scanf("%d", &n);

    int total_sum = 0;
    printf("Enter Elements : \n");
    for (int i = 0; i < n; i++) {
        printf("Enter Element %d : ", i);
        scanf("%d", &elements[i]);
        total_sum += elements[i];
        subset[i] = 0;
    }

    printf("Enter Target Sum : ");
    scanf("%d", &target);

    findSumofSubet(0, 0, total_sum);
}
