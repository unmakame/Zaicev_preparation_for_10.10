// линейный
// бинарный
// по образцу

// СОРТИРОВКИ
// вставкой - 50/50
// слиянием - repeat
// пузырьком - ok
// шейкерная - nahui
// Хоара -ok
// Шелла - ok
// Естевственным слиянием
// Слиянием


#include <stdio.h>

// void insert(int arr[], int size){ //вставкой
//     int i,j,key;
//     for (i = 0; i < size; i++){
//         key = arr[i];
//         j = i - 1;
//         while(j >= 0 && arr[j] > key){
//             arr[j + 1] = arr[j];
//             j--;
//         }
//         arr[j + 1] = key;

//     }
// }


// void bubble_sort(int arr[], int size){
//     for (int i = 0; i < size;i++){
//         for (int j = 0; j < size - i - 1;j++){
//             if(arr[j] > arr[j + 1]){
//                 int temp = arr[j];
//                 arr[j] = arr[j + 1];
//                 arr[j + 1] = temp;
//             }
//         }
//     }
// }


// void hoar_sort(int arr[], int left, int right){
//     int i = left;
//     int j = right;
//     int pivot = arr[(left + right) / 2];

//     while(i <= j){
//         while(arr[i] < pivot) i++;
//         while(arr[j] > pivot) j--;

//         if (i <= j){
//             int temp = arr[j];
//             arr[i] = arr[j];
//             arr[j] = temp;
//             i++;
//             j--;
//         }
//         if (left < j) hoar_sort(arr,left,j);
//         if (right > i) hoar_sort(arr,i,right);
//     }
// }


// void hoar_sort(int arr[], int size){
//     int stack[size];
//     int top = -1;
//     stack[++top] = 0;
//     stack[++top] = size -1;
//     while (top >= 0){
//         int right = stack[top--];
//         int left = stack[top--];
//         int pivot = arr[(left + right) / 2];
//         int i = left;
//         int j = right;

//         while(i <= j){
//             while(arr[i] < pivot) i++;
//             while(arr[j] > pivot) j--;

//             if (i <= j){
//                 int temp = arr[i];
//                 arr[j] = arr[i];
//                 arr[j] = temp;
//                 i++;
//                 j--;
//             }
//         }
//         if (left < j){
//             stack[++top] = left;
//             stack[++top] = j;
//         }
//         if (right > i){
//             stack[++top] = i;
//             stack[++top] = right;
//         }
//     }
// }

// int main() {
//     int arr[] = {60, 1000, 7, 12342, 6, 48, 149894234};  
//     int size = sizeof(arr) / sizeof(arr[0]);             

//     hoar_sort(arr, size);                          

//     printf("Отсортированный массив: ");                 
//     for (int i = 0; i < size; i++) {                     
//         printf("%d ", arr[i]);                            
//     }
//     printf("\n");                                      

//     return 0;                                          
// }


// void shella_sort(int arr[], int size){
//     int gap,i,j,temp;
//     for (gap = size/2;gap>0;gap/=2){
//         for(i=gap;i<size;i++){
//             temp = arr[i];
//             for(j = i; j >= gap && arr[j - gap] > temp;j-=gap){
//                 arr[j] = arr[j - gap];
//             }
//             arr[j] = temp;
//         }
//     }
// }


// int main() {
//     int arr[] = {5, 2, 4, 6, 1, 3};
//     int size = sizeof(arr) / sizeof(arr[0]);
    
//     printf("До сортировки: ");
//     for(int i = 0; i < size; i++) printf("%d ", arr[i]);
    
//     shella_sort(arr, size);
    
//     printf("\nПосле сортировки: ");
//     for(int i = 0; i < size; i++) printf("%d ", arr[i]);
    
//     return 0;
// }