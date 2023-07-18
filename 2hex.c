#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t byte;

void getHEXuid(char *a, byte uidByte[10]){
    const char *hex = "0123456789ABCDEF";
    for (int i = 0; i < 10; i++) {
        /*printf("byte %d\n", uidByte[i]);*/
        byte lo = uidByte[i] % 16;
        byte hi = uidByte[i] - lo;
        /*printf("hi %d\n", (int)hi / 16);*/
        /*printf("lo %d\n", (int)lo);*/
        *a++ = hex[hi / 16];
        *a++ = hex[lo];
    }
    *a = 0;
}

int main() {
    // XXX: Как понять какой длины нужен буфер?
    char buf[20] = {0};

    byte uid[10] = {255, 2, 8, 100, 0, 1, 0, 0, 200,};
    getHEXuid(buf, uid);
    printf("%s\n", buf);
}
