/*
extern void quicksort_asm(int arr[], int low, int high);
void quicksort_c(int arr[], int low, int high)
{
	if( low < high) {
		int pivot = partition_c(arr, low, high);
		quicksort_c(arr, low, pivot - 1);
		quicksort_c(arr, pivot + 1, high);
	}
}
*/
.global quicksort_asm
quicksort_asm:
