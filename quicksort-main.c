#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


#define MAX_SIZE 10000
#define LB (0 - MAX_SIZE << 2) 
#define UB (0 + MAX_SIZE << 2) 
#define TEST 

extern int partition_asm(int arr[], int low, int high);
int partition_c(int arr[], int low, int high)
{
	int base = arr[low];
	while(low < high) {
		while(low < high && arr[high] >= base)
			high--;
		arr[low] = arr[high];	// 从右边找到第一个小于或等于base的位置high

		while(low < high && arr[low] <= base)
			low++;
		arr[high] = arr[low];	// 从左边找到第一个大于或等于base的位置low
	}

	arr[low] = base;
	return low;
}

extern void quicksort_asm(int arr[], int low, int high);
void quicksort_c(int arr[], int low, int high)
{
	if( low < high) {
		int pivot = partition_c(arr, low, high);
		quicksort_c(arr, low, pivot - 1);
		quicksort_c(arr, pivot + 1, high);
	}
}


void check(int test[], int trust[], int size)
{
	for(int i = 0; i < size; i++) {
		if(test[i] != trust[i]) {
			printf("ARR[%d] SHOULD BE %d, BUT GOT %d.\n", i, trust[i], test[i]);	
			printf("TEST FALIED\n");
			return;
		}
	}
	printf("PASS TEST\n");
}

void fill_array_random(int arr[], int size, int lb, int ub) {
    srand(time(0));
	for(int i = 0; i < size; i++) {
		arr[i] = (rand() % (ub - lb + 1)) + lb;
	} 	
}

void print_array(int arr[], int size)
{
	printf("%d", arr[0]);
	for(int i = 1; i < size; i++)
		printf(", %d", arr[i]);
}

int main()
{
	int *array_asm= malloc(sizeof(int) * MAX_SIZE);
	fill_array_random(array_asm, MAX_SIZE, LB, UB);

#ifdef TEST
	int *array_c= malloc(sizeof(int) * MAX_SIZE);
	memcpy(array_c, array_asm, sizeof(int) * MAX_SIZE);
#endif

	quicksort_asm(array_asm, 0, MAX_SIZE - 1);

#ifdef TEST 
	quicksort_c(array_c, 0, MAX_SIZE - 1);
	check(array_asm, array_c, MAX_SIZE);
#endif
	// print_array(array_asm, MAX_SIZE);	
	return 0;
}
