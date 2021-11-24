#include "lab.h"
#include "utils.h"

// переводит число в строку
char *number_to_string(long long int id) {
    int number_length = number_digits_amount(id);
    char *string = (char*) malloc(sizeof(char) * (number_length + 1));
    int counter;
    for (counter = 0; counter < number_length; counter++, id /= 10) {
        char current_digit = id % 10;
        string[counter] = '0' + current_digit;
    }
    string[counter] = '\0';
    return string;
}

// ищет три последних ненулевых числа
int get_last_numbers(long long int numeric_id) {
    char *id = number_to_string(numeric_id);
    char id_size = strlen(id);
	int result = 0, operations = 0, index = 0;
    for (index = 0; index < id_size && operations < 3; index++) {
        char current_digit = id[index] - '0';
        if (current_digit != 0) {
            result += current_digit * power(10, operations);
            operations++;
        }
    }

	return result;
}

// ищет три первых ненулевых числа
int get_first_numbers(long long int numeric_id) {
    char *id = number_to_string(numeric_id);
    char id_size = strlen(id);
	int result = 0, operations = 0, index = 0;
    for (index = id_size - 1; index >= 0  && operations < 3; index--) {
        char current_digit = id[index] - '0';
        if (current_digit != 0) {
            result += current_digit * power(10, 2 - operations);
            operations++;
        }
    }

	return result;
}

int get_third_number(long long int numeric_id) {
    char *id = number_to_string(numeric_id);
    char id_length = strlen(id);
    int index = 0, counter = 0;
    for (index = id_length - 1; index >= 0; index--) {
        if (id[index] != '0') {
            counter++;
            if (counter == 3) return id[index] - '0';
        }
    }
    return 0;
}

void amount_encryption(int N, struct client *bank, struct client *bank_ciphr, struct key *ciphr) {
    for (int i = 0; i < N; i++) {
        int id = bank[i].identification_number;
        // Составить два трехзначных числа из 3-х подряд идущих младших Ненулевых цифр
        int last_numbers = get_last_numbers(id);
        // printf("The number was built by three lowerest digits – %d\n", last_numbers);
        // 3-х ненулевых старших идентификационного номера клиента
        int first_numbers = get_first_numbers(id);
        // printf("The number was built by three highest digits – %d\n", first_numbers);
        // Найти НОД этих чисел
        int gcd_multiplier = gcd(last_numbers, first_numbers);
        // printf("Found gcd for these numbers – %d\n", gcd_multiplier);
        // число, состоящее из 3-ей цифры справа идентификационного номера клиента (если она равна 0, то следующей, 4 справа)
        int third_number = get_third_number(id);
        // printf("The third from the beginning digit – %d\n", third_number);
        // полученный ключ
        int key = gcd_multiplier * third_number;
        bank_ciphr[i].amount = bank[i].amount + key;
        ciphr[i].key_2 = key;
    }
}

