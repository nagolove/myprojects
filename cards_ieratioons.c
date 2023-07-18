#include <stdlib.h>
#include <stdio.h>
int main() {
    for (int i = 0; i < 52; i++) {
        int suit = (i % 4) + 1;
        int card = 1 + i / 4;
        printf("suit %d, card %d\n", suit, card);
    }
}
