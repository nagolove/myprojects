#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

static uint32_t pow_of_2[] = {
    2,
    4,
    8,
    16,
    32,
    64,
    128,
    256,
    512,
    1024,
    2048,
    4096,
    8192,
    16384,
    32768,
    65536,
    131072,
    262144,
    524288,
    1048576,
    2097152,
    4194304,
    8388608,
    16777216,
    33554432,
    67108864,
    134217728,
    268435456,
    536870912,
    1073741824,
    2147483648,
};

uint32_t next_eq_pow2(uint32_t p) {
    int len = sizeof(pow_of_2) / sizeof(pow_of_2[0]);
    for (int i = 0; i < len - 1; i++) {
        //if (p >= pow_of_2[i] && p < pow_of_2[i + 1])
            //return pow_of_2[i + 1];
        if (pow_of_2[i] >= p)
            return pow_of_2[i];
    }
    perror("next_pow2: too big p");
    exit(EXIT_FAILURE);
}

void tst(uint32_t z) {
    printf("%u %u\n", z, next_eq_pow2(z));
}

int main() {
    tst(127);
    tst(10);
    tst(1);
    tst(0);
    tst(32);
    tst(4);
    tst(5);
    tst(2147483648);
}

