#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

bool some_action() {
    printf("some_action\n");
    return rand() % 2;
}

int main() {
    srand(time(NULL));

    printf("%s\n", some_action() ? "t" : "f");
    printf("%s\n", some_action() ? "t" : "f");
    printf("%s\n", some_action() ? "t" : "f");
    printf("%s\n", some_action() ? "t" : "f");

    bool precond = rand() % 2;
    printf("precond %s\n", precond ? "t" : "f");
    printf("\n");

   /*for (int i = 0; i < 3; i++) {*/
        bool cond1 = precond || some_action();
        printf("cond1 %s\n", cond1 ? "t" : "f");
        bool cond2 = some_action() || precond;
        printf("cond2 %s\n", cond2 ? "t" : "f");
    /*}*/

    return EXIT_SUCCESS;
}
