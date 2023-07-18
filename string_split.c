#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    const char *command = "SUM_100_32";
    /*const char *command = "SUM 100 32";*/
    
    char cmd_name[32] = {0};
    char cmd_num1[32] = {0};
    char cmd_num2[32] = {0};
    sscanf(command, "%[^_]_%[^_]_%s", cmd_name, cmd_num1, cmd_num2);

    int num1 = atoi(cmd_num1);
    int num2 = atoi(cmd_num2);

    printf("%s|%d|%d\n", cmd_name, num1, num2);

    if (!strcmp(cmd_name, "SUM")) {
        printf("SUM\n");
    } else if (!strcmp(cmd_name, "HER")) {
        printf("HER\n");
    }

    return 0;
}

