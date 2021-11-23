#include "lab.h"

int main()
{
    int i, N;
    scanf("%d", &N);

    struct currency val[5];
    struct client bank[1000];
    struct client bank_ciphr[10000];
    struct client bank_new[10000];
    struct key cipher[10000];
    struct balance total_balance;

    currency_reference(val);

    // Печать справочника валют
    printf("Справочник валют:\n");
    for (i = 0; i < 5; i++){
        printf("%10s %4s %3d\n", val[i].currency_name, val[i].leter_code, val[i].currency_code);
    }

    customer_base(N, bank, val, &total_balance);

    printf("\n");

    // Печать клиентской базы
    printf("Клиентская база:\n");
    for (i = 0; i < N; i++){
        printf("%2d %12lld %10d %10d %4d\n", i, bank[i].identification_number, bank[i].account, bank[i].amount, bank[i].code);
    }

    printf("1\n");
    account_encryption(N, bank, bank_ciphr, cipher);
    printf("2\n");
    amount_encryption (N, bank, bank_ciphr, cipher);
    printf("3\n");
    code_encryption   (N, bank, bank_ciphr, cipher);
    printf("4\n");

    printf("\nКлючи шифрования:\n");
    printf("%7s %8s %8s %8s\n", "Индекс", "key_1", "key_2", "key_3");
    for (i = 0; i < N; i++){
        printf("%7d %8d %8d %8d\n", i, cipher[i].key_1, cipher[i].key_2, cipher[i].key_3);
    }

    printf("\nПолученная клиентская база:\n");
    printf("%7s %11s %8s %7s %7s\n", "Индекс", "id_number", "account", "amount", "code");
    for (i = 0; i < N; i++){
        printf("%7d %11lld %8d %7d %7d\n", i, bank_ciphr[i].identification_number, bank_ciphr[i].account, bank_ciphr[i].amount, bank_ciphr[i].code);
    }

    
    decryption(N, bank_ciphr, bank_new, cipher, &total_balance);

    printf("Печать total_balance:\n");
    for (i = 0; i < 5; i++){
        printf("%10d %10d\n", total_balance.currency_start[i], total_balance.currency_cipher[i]);
    }



    if (verification(N, bank, bank_new) == 0) {
        printf("Stopped because of verification function\n");
        return 0;
    }

    // if (check(&total_balance) == 0) {
    //     printf("Stopped because of check function\n");
    //     return 0;
    // }

    // printf("\n:\n");
    // printf("%13s %15s %4s %9s %15s\n", "Наименование", "Буквенный код", "Код", "Исходный", "Востановленный");
    // for (i = 0; i < 5; i++){
    //     printf("%13s %15s %4d %9d %15d\n", val[i].currency_name, val[i].leter_code, val[i].currency_code, total_balance.currency_start[i], total_balance.currency_cipher[i]);
    // }

    return 0;
}
