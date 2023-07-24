#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stdint.h>
#include <string.h>
int main() {
    int8_t massiv[32];
    int massiv_len = sizeof(massiv) / sizeof(massiv[0]);
    for (int i = 0; i < massiv_len; i++) {
        massiv[i] = i;
    }

    memset(massiv + 2, 0, 1);
    for (int i = 0; i < massiv_len; i++) {
        printf("%d ", massiv[i]);
    }
    printf("\n");

    memset(massiv + 12, 0, 2);
    for (int i = 0; i < massiv_len; i++) {
        printf("%d ", massiv[i]);
    }

    printf("\n");
}
