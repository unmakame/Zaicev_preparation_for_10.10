#include <stdio.h>
#include <stdlib.h>

void quick_sort_rec(int arr[], int left, int right){
    if (left >= right) return;

    int i = left;
    int j = right;
    int pivot = arr[(left + right) / 2];

    while(i <= j){
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i <= j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    if (left < j) quick_sort_rec(arr,left,j);
    if (right > i) quick_sort_rec(arr,i,right);
    } 
}























int main() {
    int arr[] = {60, 1000, 7, 12342, 6, 48, 149894234};
    int size = sizeof(arr) / sizeof(arr[0]);

    quick_sort_rec(arr, 0, size - 1);

    printf("Отсортированный массив: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
