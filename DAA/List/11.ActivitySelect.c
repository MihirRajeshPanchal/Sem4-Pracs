#include <stdio.h>
#include <stdlib.h>

struct Activity {
    int start, finish;
};

int compare(const void *a, const void *b) {
    return ((struct Activity *)a)->finish - ((struct Activity *)b)->finish;
}

void printMaxActivities(struct Activity activities[], int n) {
    qsort(activities, n, sizeof(struct Activity), compare);

    printf("The following activities are selected:\n");

    int i = 0;
    printf("(%d, %d) ", activities[i].start, activities[i].finish);

    for (int j = 1; j < n; j++) {
        if (activities[j].start >= activities[i].finish) {
            printf("(%d, %d) ", activities[j].start, activities[j].finish);
            i = j;
        }
    }
}

int main() {
    struct Activity activities[] = {{1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9}, {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}};
    int n = sizeof(activities) / sizeof(activities[0]);
    printMaxActivities(activities, n);
    return 0;
}
