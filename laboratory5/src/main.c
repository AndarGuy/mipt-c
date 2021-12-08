#include "../inc/lab.h"

void copy_file(char *fsource, char *fdest) {
    FILE* source = fopen(fsource, "rb");
    FILE* dest = fopen(fdest, "wb");

    char buf[READ_LINE_BUFF_SIZE];
    size_t size;
    while ((size = fread(buf, 1, READ_LINE_BUFF_SIZE, source)) != 0) {
        fwrite(buf, 1, size, dest);
    }

    fclose(source);
    fclose(dest);
}

int compare_results(int n_lines) {
    FILE* answers = fopen(ASSETS_PATH "rez_.dat", "r");
    FILE* result = fopen(ASSETS_PATH "rez.dat", "r");

    int line;
    for (line = 0; line < n_lines; line++) {
        int answer_value = 0, proccessed_value = 0;
        fscanf(answers, "%d", &answer_value);
        fscanf(result, "%d", &proccessed_value);
        if (answer_value != proccessed_value) {
            printf("line %d: expected %d got %d.\n", line + 1, answer_value, proccessed_value);
            return 0;
        }
    }

    return 1;
}

void prepare_files(int n_test) {
    char *program_dst = ASSETS_PATH "program.txt";
    char *program_src = (char*) malloc(READ_LINE_BUFF_SIZE * sizeof(char));
    sprintf(program_src, ASSETS_PATH "input/program%d.txt", n_test + 1);
    // printf("Trying to copy file `%s` to `%s`\n", program_src, program_dst);
    copy_file(program_src, program_dst);
    // printf("Testing file has been copied.\n");

    char *result_dst = ASSETS_PATH "rez_.dat";
    char *result_src = (char*) malloc(READ_LINE_BUFF_SIZE * sizeof(char));
    sprintf(result_src, ASSETS_PATH "result/rez%d.dat", n_test + 1);
    // printf("Trying to copy file `%s` to `%s`\n", result_src, result_dst);
    copy_file(result_src, result_dst);
    // printf("Answer file has been copied.\n");
}

void clean_files() {
    remove(ASSETS_PATH "constant_expressions.txt");
    remove(ASSETS_PATH "rez_.dat");
    remove(ASSETS_PATH "rez.dat");
    remove(ASSETS_PATH "program.txt");
    remove(ASSETS_PATH "postfix_notation.txt");
}

int main() {

    printf("–––––Laboratory №5–––––\n\n");

    const int n_tests = 5;
    int n_test;
    for (n_test = 0; n_test < n_tests; n_test++) {
        printf("• Test №%d \n\n", n_test + 1);

        prepare_files(n_test);

        printf("Reading expressions and clipping them into `constant_expressions.txt`\n");
        int n_readed_lines = clipping_expressions();
        printf("Found %d expressions for testing file.\n", n_readed_lines);

        // printf("Trying to convert expressions.\n");        
        post_notation(n_readed_lines);
        printf("Converted expressions.\n");

        printf("Calculating values for each expression, writing `rez.dat`\n");
        calculating_value();

        printf("Compairing values... ");
        if (compare_results(n_readed_lines)) printf("OK\n");

        printf("\n");
    }

    printf("Cleaning temp files...\n\n");
    clean_files();

    return 0;
}