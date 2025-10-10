#include <stdio.h>


void sort(int arr[], int size){
    int stack[size];
    int top = -1;
    stack[++top] = 0;
    stack[++top] = size - 1;
    while(top >= 0){
        int right = stack[top--];
        int left = stack[top--];
        int i = left;
        int j = right;
        int pivot = arr[(right + left) / 2];

        while (i <= j){
            while (arr[i] < pivot) i++;
            while(arr[j] > pivot) j--;

            if (i <= j){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
        }
        if (right > i){
            stack[++top]= i;
            stack[++top] = right;
        }
        if (left < j){
            stack[++top] = left;
            stack[++top] = j;
        }
        
    }
}


int main() {
    int arr[] = {60, 1000, 7, 12342, 6, 48, 149894234};  
    int size = sizeof(arr) / sizeof(arr[0]);             

    sort(arr, size);                          

    printf("Отсортированный массив: ");                 
    for (int i = 0; i < size; i++) {                     
        printf("%d ", arr[i]);                            
    }
    printf("\n");                                      

    return 0;                                          
}
