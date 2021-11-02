#include "lab.h"

void danger_signal (int N, int *danger)
{
    char *s1 = "YES";
    char *s2 = "NO";
    printf("Индекс судна\n");
    for (int i = 0; i < N; ++i)
    {
        if (*(danger + i) == 1){ 
	       printf("%d %15s\a", i + 1, s1);
        }
        else { 
	       printf("%d %15s", i + 1, s2);
        }
        getchar();
    }
}