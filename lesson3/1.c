#include <stdio.h>
#include <ctype.h>

int main() {
    char x = getchar();
    
    if (isalpha(x)) puts("Alpha!");
    else if (isdigit(x)) puts("Digit!");
    else puts("Symbol!");

    return 0;
}

