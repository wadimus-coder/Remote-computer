#include <stdio.h>
#include <unistd.h>

struct s_cmd_pack
{
    short opcode;
    short len;
    char data[1000];
};

void print_pack(struct s_cmd_pack *obj_cmd_pack)
{
    printf("opcode : %d\n", obj_cmd_pack->opcode);
    printf("len : %d\n", obj_cmd_pack->len);
    printf("data : %s\n", obj_cmd_pack->data);
}

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
    /*
    char data[5000];
    char cmd[100] = "cd folder1";

    char new_path[100];
    // memset(new_path, 0, sizeof(new_path));
    new_path[0] = 0;
    sscanf(cmd, "cd %s", new_path);

    chdir(new_path); // change DIRectory
    exec_data("dir", data);

    printf("%s\n", data);
    return 0;
    */
    struct s_cmd_pack pack = {0, 3, "dir"};
    print_pack(&pack);
}

// opcode =0 : обычная команда
// opcode =1 : смена директории
// opcode =2 : скачать файл для редактирования
// opcode =3 : отправить отред.копию файла на сервер
