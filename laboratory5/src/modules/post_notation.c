#include "../../inc/lab.h"

void post_notation(int N) {
    FILE *constant = fopen(ASSETS_PATH "constant_expressions.txt", "r");
    FILE *post = fopen(ASSETS_PATH "postfix_notation.txt", "w");

    char array_of_strings[N][READ_LINE_BUFF_SIZE];
    for (int i = 0; i < N; ++i) {
	    fgets(array_of_strings[i], READ_LINE_BUFF_SIZE, constant);
    }

    for (int i = 0; i < N; ++i) {
        fprintf(post, "%s\n", post_conversion(array_of_strings[i]));
    }

    fclose(constant);
    fclose(post);
}