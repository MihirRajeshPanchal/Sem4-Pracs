#include <stdio.h>
#include <time.h>
#include <stdlib.h> 

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[100000], n, i;
    int choice;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Choices  : ");
    printf("\n(1). Best Case : ");
    printf("\n(2). Average Case : ");
    printf("\n(3). Worst Case : ");

    printf("\nEnter Choice : ");
    scanf("%d", &choice);

    switch(choice){
        case 1 :  
            printf("\nBest Case");
            for (i = 0; i < n; i++)
                arr[i] =  i;
            break;
        case 2 :
            printf("\nAverage Case");
            for (i = 0; i < n; i++)
                arr[i] = rand();
            break;
        case 3 :
            printf("\nWorst Case");
            for (i = n; i >= 0 ; i--)
                arr[n - i] =  i;
            break;
        default:
            break;
    }

    clock_t pre_sort_seconds;
     
    pre_sort_seconds = clock();

    insertionSort(arr, n);

    clock_t post_sort_seconds;
     
    post_sort_seconds = clock();

    clock_t timetaken = post_sort_seconds-pre_sort_seconds;
    printf("\nTime Taken %ld",timetaken);

    return 0;
}
