#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main() {
    int i = 0, j = 1;
    printf("%d\n", memcmp(&i, &j, sizeof(i)));
}


