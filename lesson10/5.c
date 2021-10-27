/*

*/

struct Student {
    char initials[100];
    int group;
    char grade[5];
};

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TASK "5"

#define MIN(a, b) a > b ? b : a
#define MAX(a, b) -MIN(-a, -b);

// int comparator(const void *a, const void *b) {
//     struct Student *word1 = (struct Student *) a;
//     struct Student *word2 = (struct Student *) b;

//     int i, N = MIN(strlen(word1->initials), strlen(word2->initials));
//     for (i = 0; i < N; i++) {
//         if (word1->initials[i] < word2->initials[i]) return 0;
//         else if (word1->initials[i] > word2->initials[i]) return 1;
//     }

//     return strlen(word1->initials) < strlen(word2->initials) ? 0 : 1;
// }

int comparator(const void *a, const void *b) {
    return strcmp(((struct Student *) a)->initials, ((struct Student *) b)->initials);
}

int main() {
    struct Student students[4] = {{"Fomenko Mikhail", 131, {5, 5, 5, 0, 0}}, {"Landau Lev", 051, {3, 4, 4, 3, 5}}, {"Tolstoy Lev", 512, {4, 5, 5, 5, 0}}, {"Evgeniy Onegin", 512, {4, 5, 5, 5, 0}}};

    qsort(students, 4, sizeof(struct Student), comparator);

    int i = 0;
    for (i = 0; i < 4; i++) {
        printf("%s\n", students[i].initials);
    }
    return 0;
}