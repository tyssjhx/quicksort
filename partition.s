/*
int partition_c(int arr[], int low, int high)
{
    int base = arr[low];
    while(low < high) {
        while(low < high && arr[high] >= base)
            high--;
        arr[low] = arr[high];   // 从右边找到第一个小于或等于base的位置high

        while(low < high && arr[low] <= base)
            low++;
        arr[high] = arr[low];   // 从左边找到第一个大于或等于base的位置low
    }

    arr[low] = base;
    return low;
}
*/

.global	partition_asm
partition_asm:
