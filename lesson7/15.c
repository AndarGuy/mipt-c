// Вывести в алфавитном порядке все слова, содержащие наибольшее количество гласных букв; 
// найти все слова, в которые буква «а» входит не менее двух раз.

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a < b ? a : b

int comparator(const void *a, const void *b) {
    char *word1 = (char*) a;
    char *word2 = (char*) b;

    int i, N = MIN(strlen(word1), strlen(word2));
    for (i = 0; i < N; i++) {
        if (word1[i] < word2[i]) return 0;
        else if (word1[i] > word2[i]) return 1;
    }

    return strlen(word1) < strlen(word2) ? 0 : 1;
}

int main() {
    char s[100];

    fgets(s, 100, stdin);

    char words[10][10];
    char nwords = 0;

    char *i;
    char *j = s;
    char temp[100];
    while ((i = strchr(s, ' ')) != NULL) {
        strncpy(temp, j, i - j);
        temp[i - j] = '\0';
        strcpy(words[nwords], temp);
        nwords++;
        j = i;
        *i = '\1';
    }

    char withA[10][10];
    int withAN = 0;
    char syllables[10][10];
    int withSN = 0;

    int max = 0;
    int k, m;
    for (k = 0; k < nwords; k++) {
        int syllable = 0;
        int a = 0;
        for (m = 0; m < strlen(words[k]); m++) {
            if (words[k][m] == 'a' || words[k][m] == 'e' ||  words[k][m] == 'i' || words[k][m] == 'o' || words[k][m] == 'u' || words[k][m] == 'y') {
                syllable++;
            }
            if (words[k][m] == 'a') a++;
        }
        max = MAX(max, syllable);
        if (a >= 2) {
            strcpy(withA[withAN], words[k]);
            withAN++;
        }
    }

    for (k = 0; k < nwords; k++) {
        int syllable = 0;
        for (m = 0; m < strlen(words[k]); m++) {
            if (words[k][m] == 'a' || words[k][m] == 'e' ||  words[k][m] == 'i' || words[k][m] == 'o' || words[k][m] == 'u' || words[k][m] == 'y') {
                syllable++;
            }
        }
        if (syllable == max) {
            strcpy(syllables[withSN], words[k]);
            withSN++;
        }
    }

    qsort(withA, withAN, sizeof(char) * 10, comparator);

    printf("Слова с двумя и более «A»:\n");

    for (k = 0; k < withAN; k++) {
        printf("%s\n", withA[k]);
    }

    qsort(syllables, withSN, sizeof(char) * 10, comparator);

    printf("Слова с максимальным кол-вом гласных:\n");

    for (k = 0; k < withSN; k++) {
        printf("%s\n", syllables[k]);
    }

    return 0;

}