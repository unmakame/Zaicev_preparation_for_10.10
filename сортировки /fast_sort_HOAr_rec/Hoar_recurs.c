#include <stdio.h>
#include <stdlib.h>


void quicksort(int *a, int l, int r) {
    if (l >= r) return; // базовый случай
    int x = a[(l + r) / 2]; // опорный элемент
    int i = l, j = r;
    while (i <= j) {
        while (a[i] < x) i++; // ищем слева
        while (a[j] > x) j--; // ищем справа
        if (i <= j) { // обмен
            int t = a[i]; a[i] = a[j]; a[j] = t;
            i++; j--;
        }
    }
    quicksort(a, l, j); // сортировка левой части
    quicksort(a, i, r); // сортировка правой части
}

int main() {
    int x[] = {4,5,2,3,1,0,9,8,6,7};
    int n = sizeof(x)/sizeof(x[0]);
    quicksort(x, 0, n-1); // сортировка массива
    for (int i = 0; i < n; i++)
        printf("%d ", x[i]); // вывод результата
    return 0;
}