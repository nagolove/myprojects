#include <stdlib.h>
#include <stdio.h>

int main() {
    FILE *some_file = fopen("some_file.txt", "w");
    int idx = 0;

    for (int i = 0; i < 5; i++) {
        fprintf(some_file, "%d\n", idx++);
        fclose(some_file);
    }
}
