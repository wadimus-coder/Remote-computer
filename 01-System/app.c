// 01-app.c
#include <stdio.h>
#include <unistd.h>

int main()
{
    char cmd[100] = "dir ";
    char cmd2[100];

    sprintf(cmd2, "%s 1>data.txt", cmd);
    printf("%s\n", cmd2);
    system(cmd2);

    char data[5000];
    FILE *file = fopen("data.txt", "r");
    fscanf(file, "%[^\xff]", data);

    fclose(file);
    printf("%s", data);

    return 0;
}