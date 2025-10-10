#include <stdio.h>



void input_sort(int arr[],int size){
    for (int i = 0; i < size; i ++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {5, 2, 4, 120, 1, 1488};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("До сортировки: ");
    for(int i = 0; i < size; i++) printf("%d ", arr[i]);
    
    input_sort(arr, size);
    
    printf("\nПосле сортировки: ");
    for(int i = 0; i < size; i++) printf("%d ", arr[i]);
    
    return 0;
}