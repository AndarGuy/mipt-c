#include "../../inc/lab.h"

void r_trim(char* str)
{
	char* end_of_expression = strchr(str, ';');
	*end_of_expression = '\0';
}

char* l_trim(char* str)
{
	while (isspace(*str)) {
		++str;
	}

	return str;
}

char* get_math_exprission_from_string(char* str)
{
	char* expression = strchr(str, '=') + 1;
	l_trim(expression);
	r_trim(expression);

	return expression;
}

int clipping_expressions()
{
	FILE* input_file = fopen(ASSETS_PATH "program.txt", "r");
	FILE* output_file = fopen(ASSETS_PATH "constant_expressions.txt", "w");

	char buff[READ_LINE_BUFF_SIZE];

	int n_readed_lines = 0;
	while (!feof(input_file)) {
		if (!fgets(buff, READ_LINE_BUFF_SIZE - 1, input_file)) {
			continue;
		}

		if (strchr(buff, '=') == NULL) {
			continue;
		}

		fprintf(output_file, "%s\n", get_math_exprission_from_string(buff));

		++n_readed_lines;
	}

	fclose(input_file);
	fclose(output_file);

	return n_readed_lines;
}