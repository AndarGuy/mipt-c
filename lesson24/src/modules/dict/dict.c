#include "dict.h"

#define DICT_SIZE 1024
#define HASH_TYPE 0 // 0 – for open hashing, 1 – for close hashing

#define DEBUG_HEADER "[DICTIONARY] "

#ifdef USE_OPENED_HASHING
Dict dict_create() {
    List *hashes = (List*) calloc(DICT_SIZE, sizeof(List*));
    Dict created = (Dict) malloc(sizeof(struct Dict));
    created->hashes = hashes;
    created->size = 0;
    return created;
}
#endif

#ifdef USE_CLOSED_HASHING
Dict dict_create() {
    Dict created = (Dict) malloc(sizeof(struct Dict));
    char *flags = (char*) malloc(sizeof(char) * DICT_SIZE);
    Pair *items = (Pair*) malloc(sizeof(Pair) * DICT_SIZE);
    created->flags = flags;
    created->items = items;
    created->size = 0;
    return created;
}
#endif

#ifdef USE_OPENED_HASHING
void dict_put(Dict dict, Data key, Data value) {
    Hash hash = data_get_hash(key);
    int index = hash % DICT_SIZE;
    Pair pair = pair_create(key, value);
    Data pair_data = pair_to_data(pair);

    // printf("%s\n", pair_to_string(pair_from_data(pair_data)));

    if (dict->hashes[index] == NULL) {
        dict->hashes[index] = list_create(pair_data, NULL);
        dict->size++;
    }
    else {
        List current_node = dict->hashes[index];
        while (current_node != NULL) {
            Pair current_pair = pair_from_data(current_node->data);
            if (data_is_equal(pair_get_key(pair), pair_get_key(current_pair))) {
                current_node->data = pair_data;
                break;
            }
            current_node = current_node->next;
        }
        if (current_node == NULL) {
            list_insert(&dict->hashes[index], 0, pair_data);
            dict->size++;
        }
    }
}
#endif

#ifdef USE_CLOSED_HASHING
void dict_put(Dict dict, Data key, Data value) {
    Hash hash = data_get_hash(key);
    int index = hash % DICT_SIZE;
    Pair pair = pair_create(key, value);

    while (index < DICT_SIZE && dict->flags[index] != 0 && !data_is_equal(pair_get_key(dict->items[index]), key)) index++;

    if (index + 2 > DICT_SIZE) printf(DEBUG_HEADER "Dictionary is full!");
    
    dict->flags[index] = 1;
    dict->items[index] = pair;
    dict->size++;
}
#endif

#ifdef USE_OPENED_HASHING
Data dict_get(Dict dict, Data key) {
    Hash hash = data_get_hash(key);
    int index = hash % DICT_SIZE;
    List node = dict->hashes[index];

    if (node == NULL) {
        // printf(DEBUG_HEADER "There ain't any gold in that river!\n");
        return (Data) {NULL, 0, TYPE_NULL};
    }

    else {
        while (node != NULL) {
            Pair current_pair = pair_from_data(node->data);
            if (data_is_equal(key, pair_get_key(current_pair))) {
                return pair_get_value(current_pair);
            }
            node = node->next;
        }
    }
    // if the item wasn't found
    return (Data) {NULL, 0, TYPE_NULL};
}
#endif

#ifdef USE_CLOSED_HASHING
Data dict_get(Dict dict, Data key) {
    Hash hash = data_get_hash(key);
    int index = hash % DICT_SIZE;

    while (index < DICT_SIZE && (dict->flags[index] == 0 || !data_is_equal(pair_get_key(dict->items[index]), key))) index++;

    if (index < DICT_SIZE) {
        return pair_get_value(dict->items[index]);
    } else {
        return (Data) {NULL, 0, TYPE_NULL};
    }

}
#endif

#ifdef USE_OPENED_HASHING
void dict_remove(Dict dict, Data key) {
    Hash hash = data_get_hash(key);
    int index = hash % DICT_SIZE;
    List node = dict->hashes[index];

    List previous = NULL;
    while (node != NULL) {
        Pair current_pair = pair_from_data(node->data);
        if (data_is_equal(key, pair_get_key(current_pair))) {
            if (previous != NULL) {
                previous->next = node->next;
            } else dict->hashes[index] = NULL;
            return;
        }
        previous = node;
        node = node->next;
    }
    

    // if the item wasn't found
    // printf(DEBUG_HEADER "Trying to remove element isn't existed!\n");
}
#endif

#ifdef USE_CLOSED_HASHING
void dict_remove(Dict dict, Data key) {
    Hash hash = data_get_hash(key);
    int index = hash % DICT_SIZE;

    while (index < DICT_SIZE && !data_is_equal(pair_get_key(dict->items[index]), key)) index++;

    if (data_is_equal(pair_get_key(dict->items[index]), key)) {
        dict->flags[index] = 0;
        free(dict->items[index]);
    }
}
#endif

#ifdef USE_OPENED_HASHING
List dict_get_items(Dict dict) {
    List items = NULL;
    int index = 0;
    for (index = 0; index < DICT_SIZE; index++) {
        List node = dict->hashes[index];
        while (node != NULL) {
            list_insert(&items, 0, node->data);
            node = node->next;
        }
    }
    return items;
}
#endif

#ifdef USE_CLOSED_HASHING
List dict_get_items(Dict dict) {
    List items = NULL;
    int index = 0;
    for (index = 0; index < DICT_SIZE; index++) {
        if (dict->flags[index] == 1) {
            list_insert(&items, 0, pair_to_data(dict->items[index]));
        }
    }
    return items;
}
#endif

#ifdef USE_OPENED_HASHING
List dict_get_keys(Dict dict) {
    List items = NULL;
    int index = 0;
    for (index = 0; index < DICT_SIZE; index++) {
        List node = dict->hashes[index];
        while (node != NULL) {
            Pair pair = pair_from_data(node->data);
            list_insert(&items, 0, pair_get_key(pair));
            node = node->next;
        }
    }
    return items;
}
#endif

#ifdef USE_CLOSED_HASHING
List dict_get_keys(Dict dict) {
    List items = NULL;
    int index = 0;
    for (index = 0; index < DICT_SIZE; index++) {
        if (dict->flags[index] == 1) {
            list_insert(&items, 0, dict->items[index]->key);
        }
    }
    return items;
}
#endif

#ifdef USE_OPENED_HASHING
List dict_get_values(Dict dict) {
    List items = NULL;
    int index = 0;
    for (index = 0; index < DICT_SIZE; index++) {
        List node = dict->hashes[index];
        while (node != NULL) {
            Pair pair = pair_from_data(node->data);
            list_insert(&items, 0, pair_get_value(pair));
            node = node->next;
        }
    }
    return items;
}
#endif

#ifdef USE_CLOSED_HASHING
List dict_get_values(Dict dict) {
    List items = NULL;
    int index = 0;
    for (index = 0; index < DICT_SIZE; index++) {
        if (dict->flags[index] == 1) {
            list_insert(&items, 0, dict->items[index]->value);
        }
    }
    return items;
}
#endif

#ifdef USE_OPENED_HASHING
bool dict_contains(Dict dict, Data value) {
    int index = 0;
    for (index = 0; index < DICT_SIZE; index++) {
        List node = dict->hashes[index];
        while (node != NULL) {
            Pair pair = pair_from_data(node->data);
            if (data_is_equal(pair_get_value(pair), value)) {
                return true;
            }
            node = node->next;
        }
    }
    return false;
}
#endif

#ifdef USE_CLOSED_HASHING
bool dict_contains(Dict dict, Data value) {
    int index = 0;
    for (index = 0; index < DICT_SIZE; index++) {
        if (dict->flags[index] == 1) {
            if (data_is_equal(dict->items[index]->value, value)) {
                return true;
            }
        }
    }
    return false;
}
#endif

#ifdef USE_OPENED_HASHING
bool dict_has_key(Dict dict, Data key) {
    int index = 0;
    for (index = 0; index < DICT_SIZE; index++) {
        List node = dict->hashes[index];
        while (node != NULL) {
            Pair pair = pair_from_data(node->data);
            if (data_is_equal(pair_get_key(pair), key)) {
                return true;
            }
            node = node->next;
        }
    }
    return false;
}
#endif

#ifdef USE_CLOSED_HASHING
bool dict_has_key(Dict dict, Data key) {
    int index = 0;
    for (index = 0; index < DICT_SIZE; index++) {
        if (dict->flags[index] == 1) {
            if (data_is_equal(dict->items[index]->key, key)) {
                return true;
            }
        }
    }
    return false;
}
#endif

bool dict_is_empty(Dict dict) {
    return dict->size == 0;
}

int dict_size(Dict dict) {
    return dict->size;
}

void dict_clear(Dict *dict) {
    return;
}

char *dict_to_string(Dict dict) {
    return dict_to_string_custom(dict, data_to_string);
}

char *dict_to_string_custom(Dict dict, char* (*to_string)(Data)) {
    // printf(DEBUG_HEADER "Trying to convert dict to string.\n");
    char *string = (char*) calloc(1024, sizeof(char));
    strcat(string, "{");
    List item = dict_get_items(dict);
	while(item != NULL) {
        Pair pair = pair_from_data(item->data);
        strcat(string, to_string(pair_get_key(pair)));
        strcat(string, ": ");
        strcat(string, to_string(pair_get_value(pair)));
        if (item->next != NULL) strcat(string, ", ");
        item = item->next;
    }
    strcat(string, "}");
    return string;
}

void dict_print_custom(Dict dict, char* (*to_string)(Data)) {
    printf("%s\n", dict_to_string_custom(dict, to_string));
}

void dict_print(Dict dict) {
    dict_print_custom(dict, data_to_string);
}