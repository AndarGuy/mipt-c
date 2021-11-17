#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "data.h"
#include "default.h"

#define DEFAULT_N_CHILDREN 2

#define DEBUG 1
#define DEBUG_PREFIX "[TREE] "

enum BypassType {
    BYPASS_SYMMETRIC = 0,
    BYPASS_DIRECT = 1,
    BYPASS_REVERSED = 2,
};

enum SearchType {
    DIRECT = 0,
    BINARY = 1,
};

/**
 * @brief Declaration of node element of tree.
 * 
 */
typedef struct node {
	Data data;
    int n_children;
	struct node **children;
} Node;

Node *tree_create(Data data);

void tree_set_children(Node *node, Node **children);

void tree_insert_child(Node *node, Node *child, int (*comparator)(Data, Data));

int tree_get_children_number(Node *node);

int tree_children_search(Node *node, Node *child, enum SearchType search_type, int (*comparator)(Data, Data));

int tree_is_children_full(Node *node);

void tree_add_node(Node **node, Node *child, int (*comparator)(Data, Data));

void tree_print(Node *node, char *format, char* (*to_string)(Data));

Node **tree_find_node(Node **node, Data data);

int tree_depth(Node *node, int current);

void tree_delete_node(Node *node, Data data);

void tree_clear_node(Node **node);

bool tree_is_balanced(Node *node);

void tree_level_print(Node *node, int N);

void tree_display(Node *root);

#endif