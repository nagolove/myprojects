#include <stdio.h>
#include <stdlib.h>

int main() {

    int arr[4][4] = {
        { 0, 0, 0, 0}, { 1, 1, 1, 1}, { 2, 2, 2, 2}, { 3, 3, 3, 3},
    };

    arr[0][2] = 9;

    int **dyn_arr = calloc(4, sizeof(dyn_arr[0]));
    for (int i = 0; i < 4; ++i) {
        dyn_arr[i] = calloc(4, sizeof(dyn_arr[0][0]));
    }

    dyn_arr[0][2] = 9;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
    printf("sizeof(arr) = %zu", sizeof(arr));

    for (int i = 0; i < 4; ++i) {
        free(dyn_arr[i]);
    }
    free(dyn_arr);

    return EXIT_SUCCESS;
}
