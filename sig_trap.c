#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
int main() {
    for (int i = 0; i < 5; ++i) {
        if (i == 4)
            raise(SIGTRAP);
        printf("%i\n", i);
    }
}
