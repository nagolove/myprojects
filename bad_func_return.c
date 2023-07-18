#include <stdio.h>
#include <string.h>

struct String {
    char buf[32];
};

char *foo() {
    static struct String x = {2};
    strcpy(x.buf, "hello!");
    return x.buf;
}

int main() {
    struct String x = {0};
    strcpy(x.buf, "hello!");
    printf("1: %s\n", x.buf);

    for (int i = 0; i < 100; i++)
        printf("2: %s\n", foo());
}
