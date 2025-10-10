#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



void sort_vstavk(int arr[], int arr_size){
    for (int i = 0; i < arr_size; i++){
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}