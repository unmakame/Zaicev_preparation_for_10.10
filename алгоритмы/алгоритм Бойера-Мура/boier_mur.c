#include <stdio.h>      // Подключение стандартной библиотеки ввода-вывода
#include <stdlib.h>     // Подключение стандартной библиотеки для работы с памятью
#include <string.h>     // Подключение библиотеки для работы со строками

#define ALPHABET_SIZE 256   // Размер алфавита (например, для ASCII)

void buildshiftTAble(char* pattern, int *shift, int m){
    for (int i = 0; i < ALPHABET_SIZE; i++){         // Для каждого символа алфавита
        shift[i] = m;                                // Изначально сдвиг равен длине шаблона
    }
    for (int i = 0; i < m - 1; i++){                 // Для каждого символа шаблона, кроме последнего
        shift[(unsigned char)pattern[i]] = m - 1 - i;// Устанавливаем сдвиг для символа из шаблона
    }
}

void boierMoon(char *text, char *pattern){
    int n = strlen(text);                            // Длина текста
    int m = strlen(pattern);                         // Длина шаблона
    int shift[ALPHABET_SIZE];                        // Таблица сдвигов
    buildshiftTAble(pattern, shift, m);              // Заполнение таблицы сдвигов

    int i = 0;                                       // Индекс в тексте
    while (i <= n - m) {                             // Пока шаблон помещается в текст
        int j = m - 1;                               // Индекс в шаблоне (с конца)
        while (j >= 0 && pattern[j] == text[i + j])  // Пока символы совпадают
            j--;                                     // Двигаемся к началу шаблона
        if (j < 0) {                                 // Если дошли до начала шаблона (совпадение)
            printf("Match at %d\n", i);              // Выводим позицию совпадения
            i += m;                                  // Сдвигаем на длину шаблона
        } else {
            i += shift[(unsigned char)text[i + j]];  // Сдвигаем согласно таблице
        }
    }    
}

int main() {
    char text[] = "ABAAABCDABC";                     // Исходный текст
    char pattern[] = "ABC";                          // Шаблон для поиска
    boierMoon(text, pattern);                        // Вызов алгоритма поиска
    return 0;                                        // Завершение программы
}
