#include <stdio.h>

struct Product {
    int id;
    int count;
    int price;
};

void display(struct Product products[], int N) {
    printf("Список товаров:\n");
    printf("Номер\tКол-во\tЦена\n");
    int i;
    for (i = 0; i < N; i++) {
        printf("%d\t%d\t%d\n", products[i].id, products[i].count, products[i].price);
    }
}

int isProductExist(int id, struct Product products[], int N) {
    int i;
    for (i = 0; i < N; i++) {
        if (products[i].id == id) {
            return 1;
        }
    }
    return 0;
}

struct Product *getProduct(int id, struct Product products[], int N) {
        int i;
    for (i = 0; i < N; i++) {
        if (products[i].id == id) {
            return &products[i];
        }
    }
    return NULL;
}

void edit(struct Product products[], int N) {
    printf("Введите номер товара для редактирования: ");
    int id;
    if (!scanf("%d", &id)) {
        char temp;
        scanf("%c", &temp);
        printf("Ввод закончен\n");
        return;
    }
    if (!isProductExist(id, products, N)) {
        printf("Товара с таким номером не существует!\n");
        edit(products, N);
        return;
    }
    printf("Введите новое кол-во товара №%d: ", id);
    int count;
    scanf("%d", &count);
    struct Product *product = getProduct(id, products, N);
    int oldCount = product -> count;
    product -> count = count;
    printf("Кол-во товара №%d успешно изменено с %d на %d\n", id, oldCount, product -> count);
    edit(products, N);
    return;
}

int main() {
    const int N = 3;
    struct Product products[N] = {{1, 5, 250}, {2, 2, 100}, {3, 10, 10}};

    while (1) {
        display(products, N);
        edit(products, N);
    }

    return 0;
}