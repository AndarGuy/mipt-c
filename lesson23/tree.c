#include "tree.h"

Node *tree_create(Data data) {
    int n_children = 2;
    Node *tree = (Node *) malloc(sizeof(Node));
    tree->data = data;
    tree->n_children = n_children;
    if (n_children > 0) {
        tree->children = (Node**) malloc(n_children);
        for (int child = 0; child < tree->n_children; child++) {
            *(tree->children + child) = NULL;
        }
    }
    return tree;
}

void tree_set_children(Node *node, Node **children) {
    int n_children = 2;
    if (n_children > 0) {
        for (int child = 0; child < MIN(n_children, node->n_children); child++) {
            *(node->children + child) = *(children + child);
        }
    }
}

void tree_insert_child(Node *node, Node *child, int (*comparator)(Data, Data)) {
    if (DEBUG) printf(DEBUG_PREFIX "Inserting child %p to the parent %p.\n", &child, node);
    if (node->n_children > 0) {
        if (DEBUG) printf(DEBUG_PREFIX "Try to search appropriate place to insert.\n");
        int index = tree_children_search(node, child, DIRECT, comparator);
        if (DEBUG) printf(DEBUG_PREFIX "Index %d was found to insert child %p.\n", index, &child);
        if (!tree_is_children_full(node) && index > 0) {
            if (DEBUG) printf(DEBUG_PREFIX "As children array isn't null, moving memory.\n");
            for (int i = node->n_children - 1; i > index; i--) {
                *(node->children + i) = *(node->children + i - 1);
            }
        }
        *(node->children + index) = child;
    }
}

int tree_get_children_number(Node *node) {
    if (DEBUG) printf(DEBUG_PREFIX "Trying to find a actual number of children of node %p.\n", &node);
    for (int child = 0; child < node->n_children; child++) {
        if (*(node->children + child) == NULL) {
            if (DEBUG) printf(DEBUG_PREFIX "Found a NULL child, so returning previous index – %d.\n", child);
            return child;
        }
    }
    if (DEBUG) printf(DEBUG_PREFIX "It seems all children are set up, so returning %d.\n", node->n_children);
    return node->n_children;
}

int tree_children_search(Node *node, Node *child, enum SearchType search_type, int (*comparator)(Data, Data)) {
    int n_real_children = tree_get_children_number(node);

    if (DEBUG) printf(DEBUG_PREFIX "Searching of appropriate index to slide down the tree.\n");

    if (search_type == DIRECT) {
        for (int child_n = 0; child_n < n_real_children; child_n++) {
            printf("%p\n", *(node->children + child_n));
            if (comparator((*(node->children + child_n))->data, child->data) > 0) {
                return child_n;
            }
        }
        return MAX(0, n_real_children - 1);
    } else if (search_type == BINARY) {
        int left_bound = 0, right_bound = n_real_children;
        while (right_bound - left_bound > 1) {
            int index = right_bound - left_bound;
            if (comparator((*(node->children + index))->data, child->data) > 0) {
                left_bound = index;
            } else {
                right_bound = index;
            }
        }
        return left_bound;
    }
    return 0;
}

int tree_is_children_full(Node *node) {
    return node == NULL || *(node->children + (node->n_children - 1)) == NULL ? 0 : 1;
}

Node **tree_find_node(Node **node, Data data) {
    if (*node == NULL) return NULL;
    if (data_is_equal((*node)->data, data)) return node;
    for (int i = 0; i < (*node)->n_children; i++) {
        Node **result = tree_find_node(&((*node)->children[i]), data);
        if (result != NULL) return result;
    }
    return NULL;
}

int tree_depth(Node *node, int current) {
    if (node != NULL) current++;
    int result = current;
    for (int i = 0; i < node->n_children; i++) {
        if (node->children[i] != NULL) result = MAX(result, tree_depth(node->children[i], current));
    }
    return result;
}

void tree_delete_node(Node *node, Data data) {
    tree_clear_node(tree_find_node(&node, data));
}

void tree_clear_node(Node **node) {
    for (int i = 0; i < (*node)->n_children; i++) {
        if ((*node)->children[i] != NULL) tree_clear_node(&((*node)->children[i]));
    }

    free((*node)->data.data);
    free(*node);
    *node = NULL;
}

void tree_add_node(Node **node, Node *child, int (*comparator)(Data, Data)) {
    if (DEBUG) printf(DEBUG_PREFIX "Adding %p to the tree %p\n", &child, node);
    if (*node == NULL) {
        if (DEBUG) printf(DEBUG_PREFIX "Tree node %p is NULL, so replacing the node.\n", node);
        *node = child;
    } else if (comparator((*node)->data, child->data) <= 0) {
        // if (DEBUG) printf(DEBUG_PREFIX "Children array of node %p is full, so trying to find appropriate index to insert.\n", node);
        // int index = tree_children_search(*node, child, DIRECT, comparator);
        // if (DEBUG) printf(DEBUG_PREFIX "Approptiate place was found on index «%d», trying to insert in the child node\n", index);
	    // tree_add_node(((*node)->children + index), child, comparator);
        tree_add_node(((*node)->children + 0), child, comparator);
    } else {
        // if (DEBUG) printf(DEBUG_PREFIX "Children array of node %p isn't full, so inserting the child.\n", node);
        // tree_insert_child(*node, child, comparator);
        tree_add_node(((*node)->children + 1), child, comparator);
    }
}

void tree_bypass(Node *node, enum BypassType bypass_type, bool (*action)(Data)) {
    if (node == NULL) return;

    switch (bypass_type) {
    case BYPASS_DIRECT:
        if (!action(node->data)) return;
        for (int i = 0; i < node->n_children; i++) {
            tree_bypass(node->children[i], bypass_type, action);
        }
        break;
    case BYPASS_SYMMETRIC:
        tree_bypass(node->children[0], bypass_type, action);
        if (!action(node->data)) return;
        tree_bypass(node->children[1], bypass_type, action);
        break;
    case BYPASS_REVERSED:
        for (int i = 0; i < node->n_children; i++) {
            tree_bypass(node->children[i], bypass_type, action);
        }
        if (!action(node->data)) return;
        break;
    
    default:
        printf(DEBUG_PREFIX "Unknown type of tree bypass!");
        break;
    }
}

void tree_print(Node *node, char *format, char* (*to_string)(Data)) {
    if (node == NULL) {
        printf("NULL "); 
        return;
    }

    printf("%s ", to_string(node->data));

    for (int child = 0; child < node->n_children; child++) {
        tree_print(*(node->children + child), format, to_string);
    }
}

bool tree_is_balanced(Node *node) {
    if (node == NULL) return true;
    bool result = true;
    for (int i = 0; i < node->n_children; i++) {
        if (node->children[i] == NULL) {
            for (int j = 0; j < node->n_children; j++) {
                if (i != j && node->children[j] != NULL) return tree_depth(node->children[j], 0) < 2;
            }
        }
        result = result && tree_is_balanced(node->children[i]);
    } 
    return result;
}

void tree_level_print(Node *node, int N) {
    if (node == NULL) return;
    N--;
    if (N == 0) data_print(node->data);
    else if (N < 0) return;
    else {
        for (int i = 0; i < node->n_children; i++) {
            tree_level_print(node->children[i], N);
        }
    }
}

char *get_arrow_by_direction(int direction) {
    if (direction > 0) {
        // if (direction > 6) return "㇀";
        // else if (direction > 3) return "࠼";
        if (direction > 1) return "/";
        // else if (direction > 1) return "᜵";
        else return "ᛸ";
    } else {
        // if (direction < -6) return "⼂";
        // else if (direction < -3) return "⟍";
        if (direction < -1) return "\\";
        // else if (direction < -1) return "〵";
        else return "ᛸ";
    }
}

void tree_fill_display(Node *node, int height, int width, Data display[height][width], int left, int right, int layer, int direction) {
    if (node == NULL) return;
    int middle = (right + left) / node->n_children;
    display[layer * 2][middle] = node->data;
    display[layer * 2 - 1][middle + (direction == 0 ? 0 : direction > 0 ? MIN(1, direction) : MAX(-1, direction))] = data_create(TYPE_STRING, get_arrow_by_direction(direction));
    tree_fill_display(node->children[0], height, width, display, left, middle, layer + 1, (middle - left) / 2);
    tree_fill_display(node->children[1], height, width, display, middle, right, layer + 1, (middle - right) / 2);
}

void tree_display(Node *root) {
    int depth = tree_depth(root, 0);
    int height = 2 * depth - 1, width = pow(2, depth);
    Data display[height][width];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            display[i][j] = data_create(TYPE_CUSTOM, 0, NULL);
        }
    }
    tree_fill_display(root, height, width, display, 0, width, 0, false);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (display[i][j].type != TYPE_CUSTOM) data_print_custom(display[i][j], data_to_string, "", "");
            else printf(" ");
        }
        printf("\n\n");
    }
}

void tree_print_properties(Node *tree) {

    printf("---Properties---\n");

    printf("Tree head node address: %p\n", tree);

    int depth = tree_depth(tree, 0);
    
    printf("Tree depth: %d\n", depth);

    printf("Balanced: %s\n", tree_is_balanced(tree) ? "YES" : "NO");
    
}