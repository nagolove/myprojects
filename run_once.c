#include <stdlib.h>
#include <stdio.h>
int main() {
    int n =0;
    do { if (n++>10) break; puts("do {} while(0)\n"); 
    } while (0);
    do { if (n++>10) break; puts("do {} while(1)\n"); 
    } while (1);
    return 0;
}
