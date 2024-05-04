#include<stdio.h>
#include<conio.h>
#include <time.h>
#include <stdlib.h>
 
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
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

    quickSort(arr, 0, n - 1);

    clock_t post_sort_seconds;
     
    post_sort_seconds = clock();

    clock_t timetaken = post_sort_seconds-pre_sort_seconds;
    printf("\nTime Taken %ld",timetaken);

    return 0;
}