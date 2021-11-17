#include "tree.h"

int comparator(Data a, Data b) {
    return data_as_int(b) - data_as_int(a);
}

char *to_string(Data a) {
    char *s = (char*) malloc(100);
    sprintf(s, "%d", *((int*) a.data));
    return s;
}

int main() {

    int N;
    scanf("%d", &N);

    Node *tree = NULL;

    for (int i = 0; i < N; i++) {
        int temp;
        scanf("%d", &temp);
        tree_add_node(&tree, tree_create(data_create(TYPE_INT, temp)), comparator);
    }

    tree_print(tree, "%s ", to_string);

    printf("\n");

    printf("-----\n");

    printf("Tree depth: %d\n", tree_depth(tree, 0));

    printf("-----\n");

    printf("Is balanced? %d\n", tree_is_balanced(tree));

    // printf("Deleting %d...\n", 9);

    // tree_delete_node(tree, data_create(TYPE_INT, 9));

    // tree_print(tree, "%s ", to_string);

    // printf("\n-----\n");

    // printf("Is balanced? %d\n", tree_is_balanced(tree));

    tree_level_print(tree, 3);

    printf("\n");

    tree_display(tree);

    return 0;
}