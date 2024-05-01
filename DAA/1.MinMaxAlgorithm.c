#include<stdio.h>
#include<stdlib.h>

int a[100], min, max;

void MinMax(int low, int high) {
	int mid, min1, max1;
	if (low == high) {
		max = min = a[low];
	}
	else if (low == high - 1) {
		if (a[low] < a[high]) {
			min = a[low];
			max = a[high];
		}
		else {
			min = a[high];
			max = a[low];
		}
	}
	else {
		mid = (low + high) / 2;
		MinMax(low, mid);
		min1 = min;
		max1 = max;
		MinMax(mid + 1, high);
		if (max1 > max)
			max = max1;
		if (min1 < min)
			min = min1;
	}
}

int main() {
	int i;
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
	for (i = 0; i < n; i++)
    {
        printf("Enter element %d : ", i + 1);
		scanf("%d", &a[i]);
    }    
	MinMax(0, n - 1);
	printf("Min: %d, Max: %d", min, max);
	return 0;
}