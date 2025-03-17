#include <stdio.h>
#include <unistd.h>

void exec_cmd(char *cmd, char *data)
{

    char cmd2[100];
    sprintf(cmd2, "%s 2>&1", cmd);
    FILE *file = popen(cmd2, "r"); // Pipe Open

    data[0] = 0;
    // memset(data, 0, sizeof(data));
    fscanf(file, "%[^\xff]", data);
    pclose(file);
}

int main()
{
    char cmd[150] = "type app.c";
    char data[3000];
    exec_cmd(cmd, data);
    printf("%s\n", data);
    return 0;
}