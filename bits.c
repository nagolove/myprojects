#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

const char *to_bitstr_uint8_t(uint8_t value) {
    static char buf[sizeof(char) * 8 + 1] = {0};
    char *last = buf;

    union {
        struct {
            unsigned char _0: 1;
            unsigned char _1: 1;
            unsigned char _2: 1;
            unsigned char _3: 1;
            unsigned char _4: 1;
            unsigned char _5: 1;
            unsigned char _6: 1;
            unsigned char _7: 1;
        } b[1];
        uint8_t u;
    } bp = { .u = value, };

    for(int i = 0; i < sizeof(value); ++i) {
        last += sprintf(last, "%d", (int)bp.b[i]._7);
        last += sprintf(last, "%d", (int)bp.b[i]._6);
        last += sprintf(last, "%d", (int)bp.b[i]._5);
        last += sprintf(last, "%d", (int)bp.b[i]._4);
        last += sprintf(last, "%d", (int)bp.b[i]._3);
        last += sprintf(last, "%d", (int)bp.b[i]._2);
        last += sprintf(last, "%d", (int)bp.b[i]._1);
        last += sprintf(last, "%d", (int)bp.b[i]._0);
        /*last += sprintf(last, " ");*/
    }

    return buf;
}


int main() {
    uint8_t k = 0;
    printf("k %s\n", to_bitstr_uint8_t(k));
    // Как сбрасывать или устанавливать бит одной командой(из нескольких операций)
    k |= 0b01;
    printf("k %s\n", to_bitstr_uint8_t(k));
    k &= 0b00;
    printf("k %s\n", to_bitstr_uint8_t(k));
    k &= 0b01;
    printf("k %s\n", to_bitstr_uint8_t(k));
    k |= 0b11;
    printf("k %s\n", to_bitstr_uint8_t(k));
    k |= 0b01;
    printf("k %s\n", to_bitstr_uint8_t(k));
    k &= 0b10;
    printf("k %s\n", to_bitstr_uint8_t(k));
    if (k & 0b01)
        printf("set\n");
    //printf("k %s\n", to_bitstr_uint8_t(k));
    return 0;
}
