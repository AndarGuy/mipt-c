#ifndef LAB_H
#define LAB_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <string.h>

#define N_CURRENCIES 5
#define CURRENCY_CODE_LENGTH 4
#define CURRENCY_NAME_LENGTH 30

/**
 * @brief Поскольку, банки работают с разными валютами, информация о виде валют, должна храниться в справочнике. Для описания валют опишем структуру, где первое поле – наименование валюты, второе – буквенный код валюты и третье – код валюты.
 * 
 */
struct currency {
    char currency_name[CURRENCY_NAME_LENGTH];
    char leter_code[CURRENCY_CODE_LENGTH];
    int currency_code;
};

/**
 * @brief Для хранения информации о клиенте используется следующая информация: уникальный идентификационный номер клиента, представляющий собой целое десятичное число, состоящее минимум из 6 цифр и максимум из 10, номер счета, сумма на этом счете и код валюты (значение поля currency_code из справочника валют).
 * 
 */
struct client {
  long long int identification_number;
   int account;
   int  amount;
   int code;
};

/**
 * @brief При формировании индивидуальных ключей будем записывать их в массив структур struct key ciphr[10000].
 * 
 */
struct key {
    int ind_num;
    int key_1;
    int key_2;
    int key_3;
};

/**
 * @brief Опишем структуру для хранения баланса по валютам в открытом и зашифрованном виде.
 * 
 */
struct balance {
    int currency_start[N_CURRENCIES];
    int currency_cipher[N_CURRENCIES];
};

/**
 * @brief В результате работы этой функции получим заполненный справочник валют. 
 * 
 * @param val в качестве параметров передаем указатель на массив структур, хранящий наименования и коды 5-ти валют.
 */
void currency_reference(struct currency *val);

/**
 * @brief В результате работы этой функции получим заполненный массив данных клиентов и вычисленное значение поле val_start переменной total_balance.
 * 
 * @param N введенное количество клиентов банка
 * @param bank указатель на массив структур, хранящий клиентскую базу
 * @param val справочник валют
 * @param total_balance указатель на переменную total_balance
 */
void customer_base(int N, struct client *bank,  struct currency *val, struct balance *total_balance); 

/**
 * @brief В этой функции получаем ключ для шифрования для поля account, шифруем это поле, записываем его в массив bank_shifrа ключ в поле k_l1 массива структур shifr. 
 * 
 * @param N введенное количество клиентов банка
 * @param bank указатель на массив структур, хранящий открытую клиентскую базу
 * @param bank_ciphr указатель на массив структур, хранящий зашифрованную клиентскую базу
 * @param ciphr указатель на массив структур, хранящий ключи шифровки
 */
void account_encryption(int N, struct client * bank,  struct client * bank_ciphr, struct key *ciphr); 

/**
 * @brief В этой функции получаем ключ для шифрования для поля amount, шифруем это поле, записываем его в массив bank_shifrа ключ в поле k_l2 массива структур shifr. 
 * 
 * @param N введенное количество клиентов банка
 * @param bank указатель на массив структур, хранящий открытую клиентскую базу
 * @param bank_ciphr указатель на массив структур, хранящий зашифрованную  клиентскую базу
 * @param ciphr указатель на массив структур, хранящий ключи шифровки
 */
void amount_encryption(int N, struct client * bank,  struct client * bank_ciphr, struct key *ciphr);

/**
 * @brief В этой функции получаем ключ для шифрования для поля code, шифруем это поле, записываем его в массив bank_shifrа ключ в поле k_l3 массива структур shifr.
 * 
 * @param N введенное количество клиентов банка
 * @param bank указатель на массив структур, хранящий открытую клиентскую базу
 * @param bank_ciphr указатель на массив структур, хранящий зашифрованную  клиентскую базу
 * @param ciphr указатель на массив структур, хранящий ключи шифровки
 */
void code_encryption(int N, struct client * bank,  struct client * bank_ciphr, struct key *ciphr);

/**
 * @brief Функция реализует решето Эратосфена.
 * 
 * @param n номер простого числа, которое мы хотим получить
 * @return int требуемое простое число
 */
int resheto(int n);

/**
 * @brief Функция для получания НОДа двух чисел.
 * 
 * @param n первое число
 * @param m второе число
 * @return long long int НОД этих чисел
 */
int nod(int n, int n1);

/**
 * @brief Функция для нахождения числа сочетаний.
 * 
 * @param n сумму цифр номера счета
 * @param m код валюты
 * @return long long int число сочетаний
 */
long long int combination(int n, int m);

/**
 * @brief В этой функции получаем восстановленную клиентскую базу и посчитанный баланс по восстановленной клиентской базе.
 * 
 * @param N количество клиентов банка
 * @param bank_ciphr указатель на массив структур, хранящий зашифрованную клиентскую базу
 * @param bank_new указатель на массив структур, хранящий восстановленную  клиентскую базу
 * @param shiphr указатель на массив структур, хранящий ключи шифрования
 * @param total_balans переменная, в которой хранится общий баланс
 */
void decryption(int N, struct client *bank_ciphr, struct client *bank_new, struct key *shiphr, struct balance *total_balans);

/**
 * @brief В результате работы этой функции получаем 1, если все поля исходной и восстановленной баз совпадают и 0, если произошла ошибка. В случае возникновения ошибки, процесс дальнейшего сравнения завершается и выдается имя поля, значения которого не совпали.
 * 
 * @param N введенное количество клиентов банка
 * @param bank указатель на массив структур, хранящий открытую клиентскую базу
 * @param bank_new указатель на массив структур, хранящий восстановленную  клиентскую базу
 * @return int 1, если все поля исходной и восстановленной баз совпадают, иначе 0.
 */
int verification(int N, struct client *bank, struct client *bank_new);

/**
 * @brief В результате работы этой функции получаем 1, если все поля исходной и восстановленной баз совпадают и 0, если произошла ошибка. В случае возникновения ошибки, процесс дальнейшего сравнения завершается и выдается индекс валюты, по которой данные не совпали.
 * 
 * @param total_balance переменная, в которой хранятся баланс по валютам исходной и восстановленной клиентской базы
 * @return int 1, если все поля исходной и восстановленной баз совпадают, иначе 0.
 */
int check(struct balance *total_balance);

#endif