#include <stdio.h>
#include <conio.h>

int binarySearch(int arr[], int n, int data) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == data) {
            return mid; 
        } else if (arr[mid] < data) {
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }

    return -1; 
}

int main() {
    int arr[10], n, i, data;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements (in ascending order):\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the element to be searched: ");
    scanf("%d", &data);

    int result = binarySearch(arr, n, data);

    if (result != -1)
        printf("%d found at position %d\n", data, result + 1);
    else
        printf("%d not found\n", data);

    return 0;
}
