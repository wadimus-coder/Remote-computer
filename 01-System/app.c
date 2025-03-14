// 01-app.c
#include <stdio.h>
#include <unistd.h>

int main()
{
    char cmd[100] = "diri ";
    char cmd2[100];
    char cmd3[100];
    sprintf(cmd2, "%s 1> data.txt", cmd);
    sprintf(cmd3, "%s 2> err.txt ", cmd);
    printf("%s\n", cmd2);
    system(cmd2);
    system(cmd3);
    int ret = system(cmd3);
    printf("ret :%d\n", ret);

    // char data[5000];
    // FILE *file = fopen("data.txt", "r");
    // fscanf(file, "%[^\xff]", data);

    // fclose(file);
    // printf("%s", data);

    FILE *file1;
    if (ret == 0)
        file1 = fopen("datd.txt", "r");
    else
        file1 = fopen("err.txt", "r");
    char data[5000];
    fscanf(file1, "%[^\xff]", data);

    fclose(file1);

    printf("%s\n", data);

    return 0;
}