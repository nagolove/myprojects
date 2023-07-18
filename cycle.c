#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

char *to_bitstr32(uint32_t value) {
    static char buf[sizeof(uint32_t) * 8 + 1] = {0};
    char *last = buf;

    union {
        uint32_t u;
        struct {
            unsigned char _0: 1;
            unsigned char _1: 1;
            unsigned char _2: 1;
            unsigned char _3: 1;
            unsigned char _4: 1;
            unsigned char _5: 1;
            unsigned char _6: 1;
            unsigned char _7: 1;
        } b[4];
    } bp = { .u = value, };

    for(int i = sizeof(value) - 1; i >= 0; i--) {
        last += sprintf(last, "%d", (int)bp.b[i]._7);
        last += sprintf(last, "%d", (int)bp.b[i]._6);
        last += sprintf(last, "%d", (int)bp.b[i]._5);
        last += sprintf(last, "%d", (int)bp.b[i]._4);
        last += sprintf(last, "%d", (int)bp.b[i]._3);
        last += sprintf(last, "%d", (int)bp.b[i]._2);
        last += sprintf(last, "%d", (int)bp.b[i]._1);
        last += sprintf(last, "%d", (int)bp.b[i]._0);
    }

    return buf;
}

int f(int x) {
    int count = 0;
    while (x) {
        count++;
        /*printf("x             : %40.40s\n", to_bitstr32(*((int*)&x)));*/
        int tmp = x - 1;
        /*printf("x - 1         : %40.40s\n", to_bitstr32(*((int*)&tmp)));*/
        ///////////////////
        x = x & (x - 1);
        // x = x & (x - 1); // для x = 2^n
        ///////////////////
        /*printf("x & (x - 1)   : %40.40s\n", to_bitstr32(*((int*)&x)));*/
        /*printf("\n");*/
    }
    return count;
}

void test(int j) {
    printf("x = %d, count =  %d\n", j, f(j));
}

int main() {
    //printf("%s\n", to_bitstr32(1));
    //printf("%s\n", to_bitstr32(ceil(pow(2, 9))));
    //printf("%s\n", to_bitstr32(UINT32_MAX));
    for (int i = 0; i < 100; ++i) {
        test(i);
    }
}
