#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void printArray(int A[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
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

    mergeSort(arr, 0, n - 1);

    clock_t post_sort_seconds;
     
    post_sort_seconds = clock();

    clock_t timetaken = post_sort_seconds-pre_sort_seconds;
    printf("\nTime Taken %ld",timetaken);

    return 0;

    
}
