#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <assert.h>

/*
// Пример разделения с strtok
int main() {
    char input[] = "[   5 6]  [ 1 2 ] [0 3]       [ 7 8 ]";
    char *token = strtok(input, " []");
    int count = 0;

    while (token != NULL) {
        if (count % 2 == 0) {
            printf("%s, ", token);
        } else {
            printf("%s\n", token);
        }

        token = strtok(NULL, " []");
        count++;
    }

    return 0;
}
*/

/*
   Разбирает строчку вида " [5 6]    [ 1  2][0  3 ] [ 7 8 ]"
   Не больше 128 пробелов между цифрами.
   Возвращает количество найденных пар и два указателя на массивы с первыми 
   числами и вторыми числами.
*/
void parse_bracketed_string(
        const char *str, int **first, int **second, int *len
) {
    assert(str);
    assert(first);
    assert(second);
    assert(len);

    *len = 0;
    int cap = 10;

    *first = calloc(cap, sizeof(int));
    assert(*first);
    *second = calloc(cap, sizeof(int));
    assert(*second);

    const char *p = str;
    while (*p) {
        if (*p == '[') {
            p++;
            const char *substr = p;
            while (*substr++ != ']');
            char substr_buf[128] = {};
            int substr_len = substr - p;
            printf("len %d\n", substr_len);
            assert(sizeof(substr_buf) > substr_len);
            memmove(substr_buf, p, substr_len);
            printf("substr_buf: %s\n", substr_buf);
            int first_num, second_num;
            sscanf(substr_buf, "%d %d", &first_num, &second_num);

            if (*len == cap) {
                cap *= 2;
                *first = realloc(*first, sizeof(int) * cap);
                *second = realloc(*second, sizeof(int) * cap);
            }
            **first++ = first_num;
            **second++ = second_num;
            (*len)++;
            p += substr_len;
        }
        p++;
    }
}

int main() {
    char *str = " [5 6]    [ 1  2][0  3 ] [ 7 8 ]";
    int *firsts = NULL, *seconds = NULL;
    int len = 0;
    parse_bracketed_string(str, &firsts, &seconds, &len);
    for (int i = 0; i < len; i++) {
        printf("%d %d\n", firsts[i], seconds[i]);
    }

    free(firsts);
    free(seconds);

    return 0;
}
