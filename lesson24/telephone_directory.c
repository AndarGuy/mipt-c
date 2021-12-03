#include "modules/dict/dict.h"

int main() {

    Data key = data_create(TYPE_STRING, "key"), value = data_create(TYPE_STRING, "value");

    Dict dict = dict_create();

    printf("Dictionary created!\n");

    dict_put(dict, key, value);

    printf("Added value to the dictionary!\n");

    printf("The size of dictionary is %d\n", dict_size(dict));

    Data stored_value = dict_get(dict, key);

    printf("%p\n", stored_value.data);

    printf("The value of key %s is %s\n", data_to_string(key), data_to_string(stored_value));

    dict_print(dict);
    
    return 0;
}