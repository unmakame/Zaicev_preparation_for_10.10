#include <stdio.h>

#define STACK_SIZE 100

void quick_sort(int array[], int size) {
    int stack_left[STACK_SIZE], stack_right[STACK_SIZE], stack_top = -1;
    stack_left[++stack_top] = 0;
    stack_right[stack_top] = size - 1;

    while (stack_top >= 0) {
        int current_left = stack_left[stack_top];
        int current_right = stack_right[stack_top--];

        while (current_left < current_right) {
            int pivot_value = array[(current_left + current_right) / 2];
            int left_index = current_left, right_index = current_right;

            while (left_index <= right_index) {
                while (array[left_index] < pivot_value) left_index++;
                while (array[right_index] > pivot_value) right_index--;
                if (left_index <= right_index) {
                    int temp = array[left_index];
                    array[left_index] = array[right_index];
                    array[right_index] = temp;
                    left_index++;
                    right_index--;
                }
            }

            if (right_index - current_left > current_right - left_index) {
                if (current_left < right_index) {
                    stack_left[++stack_top] = current_left;
                    stack_right[stack_top] = right_index;
                }
                current_left = left_index;
            } else {
                if (left_index < current_right) {
                    stack_left[++stack_top] = left_index;
                    stack_right[stack_top] = current_right;
                }
                current_right = right_index;
            }
        }
    }
}

int main() {
    int numbers[] = {34, 7, 23, 32, 5, 62};
    int count = sizeof(numbers) / sizeof(numbers[0]);
    for (int i = 0; i < count; i++) printf("%d ", numbers[i]);
    printf("\n");
    quick_sort(numbers, count);
    for (int i = 0; i < count; i++) printf("%d ", numbers[i]);
    printf("\n");
    return 0;
}
