#include "lab.h"

void currency_reference(struct currency* val) {
    for (int i = 0; i < 5; ++i) {
        scanf("%s", val[i].currency_name);
        scanf("%s", val[i].leter_code);
        scanf("%d", &val[i].currency_code);
    }
}

int find_code(int code, struct currency* val) {
    for (int i = 0; i < 5; ++i) {
        if (code == val[i].currency_code) {
            return i;
        }
    }
    return -1;
}

void customer_base(int N, struct client* bank, struct currency* val, struct balance* total_balance)
{
    for (int i = 0; i < 5; ++i) {
        total_balance->currency_start[i] = 0;
    }

    for (int i = 0; i < N; ++i) {
        while (1) {
            int dummy;
            scanf("%d", &dummy);
            scanf("%lld", &bank[i].identification_number);
            scanf("%d", &bank[i].account);
            scanf("%d", &bank[i].amount);
            scanf("%d", &bank[i].code);

            int idx = 0;
            if ((idx = find_code(bank[i].code, val)) != -1) {
                total_balance->currency_start[idx] += bank[i].amount;
                break;
            }
            else printf("Currency code is incorrect. Please, repeat your input. \n");
        }
    }
}