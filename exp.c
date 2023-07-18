#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <math.h>

int _pow(int x, int p) {
    int r = x;
    for (int i = 1; i < p; ++i)
        r *= x;
    return r;
}

int _exp(float x) {
    assert(sizeof(x) == sizeof(int));
    return ((*(int*)&x) << 1) >> 24;
}

int _frac(float x) {
    assert(sizeof(x) == sizeof(int));
    return 1 + (((*(int*)&x) << 9) >> 9);
}

int main() {
    printf("%zu\n", sizeof(int));
    printf("%zu\n", sizeof(long int));

    assert(_pow(2, 5) == 32);
    assert(_pow(1, 5) == 1);
    assert(_pow(10, 3) == 1000);
    assert(_pow(3, 3) == 27);

    float x = 0.15625;
    int e = _exp(x);
    printf("e %d\n", e);
    int f = _frac(x);
    printf("f %d\n", f);
    printf("%d\n", _pow(e, f));
    printf("%d\n", _pow(f, e));
    printf("%d\n", 128 * pow(2, 3));
    /*printf("%e\n", x);*/
}
