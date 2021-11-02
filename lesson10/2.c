#include <stdio.h>

struct Date {
    int month;
    int year;
};

void input(struct Date *date) {
    printf("Введите дату в формате месяц/год: ");
    int month, year;
    scanf("%d/%d", &month, &year);
    date -> month = month;
    date -> year = year;
    return;
}

int check(struct Date dates[]) {
    if (dates[0].year <= dates[1].year && dates[1].year <= dates[2].year) {
        if (dates[0].month <= dates[1].month && dates[1].month <= dates[2].month) {
            return 1;
        }
    }
    return 0;
}

int main() {
    struct Date dates[3] = {{01, 2020}, {}, {06, 2020}}; 

    input(&dates[1]);
    
    if (check(dates)) printf("Дата входит в диапазон с 01.20 по 06.20");
    else printf("Дата не входит в диапазон с 01.20 по 06.20");
    
    return 0;
}
