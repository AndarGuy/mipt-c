/*
Надо написать  программу, которая умеет играть в карты. 
В колоде 52 карты. Карта хранится в виде структуры
*/

#include <stdio.h>
#include <string.h>

#define TASK "12"
#define AUTHOR "fomenko.ms"

#define MIN(a, b) a > b ? b : a
#define MAX(a, b) a < b ? b : a

struct Card {
    char rank;    // достоинство
    char suit;    // масть
};

/*
Масти кодируются как 'c' (clubls - трефы), 's' (spades - пики), 'h' (hearts - червы) и 'd' (diamond - бубны).
Достоинство кодируется как '2', '3', '4', '5', '6', '7', '8', '9', 
'T' (ten - десять), 'J' (валет), 'Q' (дама), 'K' (король), 'A' (туз).
В этой нотации дама пик и король бубен записываются как QsKd.
*/

char suite[] = "cshd";
char rank[] = "23456789TJQKA";

/* 
Решение реализуйте в виде функции,  которая ищет ровно одну тройку карт одинакового 
достоинства в переданной руке.
*/

int check(struct Card hand[]);

int check(struct Card hand[]) {
    int cards[strlen(rank)];
    int i = 0;
    for (i = 0; i < strlen(rank); i++) cards[i] = 0;

    i = 0;
    while (hand[i].rank != 0 && hand[i].suit != 0) {
        cards[strchr(rank, hand[i].rank) - rank]++;
        i++;
    }

    int result = -2;
    i = 0;
    for (i = 0; i < strlen(rank); i++) {
        if (cards[i] == 3) {
            if (result == -2) result = i;
            else {
                result = -1;
                break;
            }
        }
    }

    return MAX(-1, result);
}

int main() {
    FILE *fileA = fopen(TASK "_a.txt", "r"), *fileB = fopen(TASK "_b.txt", "w");

    while (!feof(fileA)) {
        char temp[100];
        fscanf(fileA, "%s", temp);
        int N = strlen(temp) / 2 + 1;
        struct Card hand[N];
        int i = 0;
        for (i = 0; i < N; i++) {
            hand[i].rank = temp[i * 2];
            hand[i].suit = temp[i * 2 + 1];
        }
        hand[i].rank = hand[i].suit = 0;

        i = 0;
        for (i=0; hand[i].rank != 0; i++) {
            fprintf(fileB, "%c%c", hand[i].rank, hand[i].suit);
        }
        fprintf(fileB, "\n");
        fprintf(fileB, "%d\n", check(hand));
    }

    return 0;
}