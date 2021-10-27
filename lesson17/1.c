/*

*/

#include <stdio.h>
#include <stdlib.h>

#define TASK "1"

#define MIN(a, b) a > b ? b : a
#define MAX(a, b) a > b ? a : b

typedef struct list {
	int data;
	struct list *next;
} List;

void print_list(List*);

void print_list(List *head)
{
	List *current;
	current = head;
	while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
	return;
}

int main() {
    List *head=NULL, *current, *prev;

	int i, n;
    scanf("%u", &n); 
	for(i = 0; i < n; i++) { 
        current = (List*) malloc(sizeof(List));
		if (head == NULL) head = current;
		else prev->next = current;
		scanf("%d", &current->data);
		current->next = NULL;
		prev = current;
	}
    print_list(head);


    return 0;
}