#include "modules/dict/dict.h"

#define STRING_SIZE 1024

void printf_command_list();

void command_help(Dict dict, char (*arguments)[STRING_SIZE]);

void command_add(Dict dict, char arguments[2][STRING_SIZE]);

void command_pop(Dict dict, char arguments[1][STRING_SIZE]);

void command_idx(Dict dict, char arguments[1][STRING_SIZE]);

struct Command {
    char* cmd;
    char* description;
    int arguments;
    void (*handler)(Dict, char (*)[STRING_SIZE]);
};

void command_help(Dict dict, char (*arguments)[STRING_SIZE]) {
    printf("Справочная информация:\n");
    printf_command_list();
}

void command_add(Dict dict, char arguments[2][STRING_SIZE]) {
    char *name = arguments[0];
    char *number = arguments[1];
    dict_put(dict, STRING(name), STRING(number));
    printf("Номер телефона \"%s\" успешно сохранен!\n", name);
}

void command_pop(Dict dict, char arguments[1][STRING_SIZE]) {
    char *name = arguments[0];
    dict_remove(dict, STRING(name));
}

void command_idx(Dict dict, char arguments[1][STRING_SIZE]) {
    char *name = arguments[0];
    Data result = dict_get(dict, STRING(name));
    if (result.type == TYPE_NULL) {
        printf("Номер телефона \"%s\" не найден!\n", name);
    } else {
        printf("Номер телефона для \"%s\" – %s\n", name, data_to_string(result));
    }
}

struct Command commands[] = {
    {"help", "показать справочную информацию.", 0, command_help}, 
    {"add", "добавить человека в записную книгу.", 2, command_add},
    {"pop", "добавить человека из записной книги.", 1, command_pop},
    {"get", "найти человека в записной книге.", 1, command_idx},
    {"exit", "завершить программу.", 0, NULL},
};
const int TOTAL_COMMANDS = 5;

void printf_command_list() {
    int n_command = 0;
    for (n_command = 0; n_command < TOTAL_COMMANDS; n_command++) {
        printf("• %s – %s\n", commands[n_command].cmd, commands[n_command].description);
    }
}

void command_handler(Dict dict) {
    while (1) {
        printf("Введите комманду:\n");
        char *cmd = malloc(sizeof(char) * STRING_SIZE);
        scanf("%s", cmd);
        bool was_cmd_found = false;
        int n_cmd = 0;
        for (n_cmd = 0; n_cmd < TOTAL_COMMANDS; n_cmd++) {
            if (strcmp(cmd, commands[n_cmd].cmd) == 0) {
                if (commands[n_cmd].handler == NULL) return;
                int n_args = commands[n_cmd].arguments;
                char args[n_args][STRING_SIZE];
                if (n_args > 0) {
                    int n_arg = 0;
                    for (n_arg = 0; n_arg < n_args; n_arg++) {
                        scanf("%s", args[n_arg]);
                    }
                }
                commands[n_cmd].handler(dict, args);
                was_cmd_found = true;
                break;
            }
        }
        if (!was_cmd_found) printf("Комманда не найдена!\n");
    }
}

int main() {

    printf("-----Тел. книга-----\n");
    printf("Список команд:\n");
    printf_command_list();

    Dict dict = dict_create();

    command_handler(dict);
    
    return 0;
}