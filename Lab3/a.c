#include<stdio.h>
#include<string.h>
#include <stdbool.h>
#include<stdlib.h>

int opcount=0;

void swap(int* xp, int* yp)
{
	opcount++;
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSort(int arr[], int n)
{
	int i, j;
	bool swapped;
	for (i = 0; i < n - 1; i++) {
		swapped = false;
		for (j = 0; j < n - i - 1; j++) {
			opcount++;
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
}

int main()
{
	printf("\nEnter size of array: \n");
	int n;
	scanf("%d",&n);
	int* arr = (int *)malloc(sizeof(int) * n);
	printf("\nEnter array elements: \n");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	bubbleSort(arr, n);
	printf("\nOpCount: %d\n",opcount);
	printf("Sorted array: \n");
	printArray(arr, n);
	return 0;
}
