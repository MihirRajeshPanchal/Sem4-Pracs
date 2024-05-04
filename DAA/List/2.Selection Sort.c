#include<stdio.h>
#include<conio.h>
#include <time.h>
#include <stdlib.h>
 
void printArray(int a[], int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void selectionSort(int a[], int n){
    int i, j, minIndex, temp;
    for(i = 0; i < n-1; i++){
        minIndex = i;
        for(j = i+1; j < n; j++){
            if(a[j] < a[minIndex]){
                minIndex = j;
            }
        }
        temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
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

    selectionSort(arr, n);

    clock_t post_sort_seconds;
     
    post_sort_seconds = clock();

    clock_t timetaken = post_sort_seconds-pre_sort_seconds;
    printf("\nTime Taken %ld",timetaken);

    return 0;
}