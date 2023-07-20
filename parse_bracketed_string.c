#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBSTRINGS 10

int main() {
    char input[] = "[5 6] [1 2] [0 3] [7 8]";
    int numbers[MAX_SUBSTRINGS];
    int count = 0;

    // Разделение строки на подстроки с использованием пробелов в качестве разделителей
    char* token = strtok(input, " ");
    while (token != NULL) {
        // Преобразование подстроки в целое число
        int number = atoi(token);
        // Добавление числа в массив
        numbers[count++] = number;
        // Переход к следующей подстроке
        token = strtok(NULL, " ");
    }

    // Вывод массива чисел
    for (int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");


    printf("%d\n", atoi("-67h"));
    printf("%d\n", atoi("-607 h"));
    printf("%d\n", atoi("8 h"));

    return 0;
}
