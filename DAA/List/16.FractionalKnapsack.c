#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value;
    int weight;
};

int compare(const void *a, const void *b) {
    double ratio1 = (double)((struct Item *)a)->value / ((struct Item *)a)->weight;
    double ratio2 = (double)((struct Item *)b)->value / ((struct Item *)b)->weight;
    return ratio2 > ratio1 ? 1 : -1;
}

double fractionalKnapsack(int capacity, struct Item items[], int n) {
    qsort(items, n, sizeof(struct Item), compare);
    double totalValue = 0.0; 
    int currentWeight = 0;  
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            totalValue += items[i].value;
            currentWeight += items[i].weight;
        } else {
            int remainingWeight = capacity - currentWeight;
            totalValue += (double)items[i].value / items[i].weight * remainingWeight;
            break; 
        }
    }
    return totalValue;
}

int main() {
    int capacity = 50;
    struct Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(items) / sizeof(items[0]);

    double maxValue = fractionalKnapsack(capacity, items, n);
    printf("Maximum value in knapsack = %.2f\n", maxValue);

    return 0;
}
