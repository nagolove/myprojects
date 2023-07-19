#include <stdio.h>
#include <stdlib.h>
int main() {
    char buf[2000] = {};
    char *p = buf;
    p += sprintf(p, "%s", "privet");
    p += sprintf(p, "%s", " ");
    p += sprintf(p, "%s", "kak");
    p += sprintf(p, "%s", " ");
    p += sprintf(p, "%s", "dela");
    p += sprintf(p, "%s", " ?");
    p += sprintf(p, "%s", "\n");
    printf("%s\n", buf);
}
