/*
Дано натуральное число n < 10^1000. 
Напечатать YES, если число делится на 3, иначе напечатать NO. 
Число делится на 3, если сумма всех его цифр делится на 3.
*/

#include <stdio.h>
#include <string.h>

int main() {
    char s[1000 + 1];
    scanf("%s", s);
    
    int i = 0, sum = 0, N = strlen(s);
    for (i = 0; i < N; i++) {
        sum += s[i] - '0';
    }

    if (sum % 3 == 0) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}