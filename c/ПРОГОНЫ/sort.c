#include <stdio.h>


void shella_sort(int arr[], int size){
    int gap,i,j,temp;
    for (gap = size/2;gap>0;gap/=2){
        for(i = gap; i < size; i++){
            temp = arr[i];
            for(j = i; j >= gap && arr[j - gap] > temp; j-=gap){
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {
    int arr[] = {5, 2, 4, 6, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("До сортировки: ");
    for(int i = 0; i < size; i++) printf("%d ", arr[i]);
    
    shella_sort(arr, size);
    
    printf("\nПосле сортировки: ");
    for(int i = 0; i < size; i++) printf("%d ", arr[i]);
    
    return 0;
}