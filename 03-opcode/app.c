#include <stdio.h>
#include <unistd.h>

void exec_data(char *cmd, char *data)
{

    char cmd2[100];

    sprintf(cmd2, "%s 2>&1 ", cmd);
    FILE *file = popen(cmd2, "r"); // pipe open

    // memset(data, 0, sizeof(data));
    data[0] = 0;
    fscanf(file, "%[^\xff]", data);

    pclose(file);
    // printf("%s\n", data);
}

int main()
{
    char cmd[100] = "dir";
    char data[5000];
    exec_data(cmd, data);

    // printf("%s\n", data);
    return 0;
}