int mul(int a, int b) {
    return sizeof(char[a][b]);
}
#include <stdio.h>
#include <stdlib.h>
int main(int, char **argv) {
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    /*printf("a %d\n", a);*/
    /*printf("b %d\n", b);*/
    printf("%d\n", mul(a, b));
}


