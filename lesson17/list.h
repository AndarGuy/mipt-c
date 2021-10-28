/**
 * @brief Declaration of custom data is used for list.
 * 
 */
typedef struct listdata {
	void *data;
	size_t size;
} ListData;

/**
 * @brief Declaration of list chain element.
 * 
 */
typedef struct list {
	ListData data;
	struct list *next;
} List;

int list_data_compatible(ListData a, ListData b);

int list_data_is_equal(ListData a, ListData b);

/**
 * @brief The function creates a chain of list.
 * 
 * @param data Data to store in chain.
 * @param next Pointer to the next chain.
 * 
 * @return List* Pointer to created chain.
 */
List *list_create(ListData data, List *next);

/**
 * @brief The function provides an index of known element.
 * 
 * @param list Pointer to list head.
 * @param data Data to search for.
 * 
 * @return int The function returns the index of element. If element is not found, it will return -1.
 */
int list_index(List *list, ListData data);

/**
 * @brief The function counts size of list.
 * 
 * @param list Pointer to list head.
 * @return int The size of list.
 */
int list_size(List *list);

/**
 * @brief The function prints list values.
 * 
 * @param head Pointer to list head.
 * @param format Format of printing value.
 * @param to_string Function that transforms ListData to string.
 */
void list_print(List *head, char *format, char* (*to_string)(ListData));

/**
 * @brief The function adds element to end of list.
 * 
 * @param _list Pointer of pointer of list head.
 * @param data Value which is required to be added.
 */
void list_push(List **_list, ListData data);

/**
 * @brief The function inserts a value to the list.
 * 
 * @param _list Pointer of pointer of list head.
 * @param position Position in list to insert the value.
 * @param data Value to insert.
 */
void list_insert(List **_list, int position, ListData data);

/**
 * @brief The function clears the list.
 * 
 * @param list Pointer of pointer of list head.
 */
void list_clear(List **list);

/**
 * @brief The function removes the last element of the list
 * 
 * @param _list Pointer of pointer of list head.
 */
void list_pop(List **_list);

/**
 * @brief The function removes the selected chain from the list.
 * 
 * @param _list Pointer of pointer of list head.
 * @param position Position of chain to remove.
 */
void list_remove(List **_list, int position);

/**
 * @brief The function saves the list to file.
 * 
 * @param list Pointer of list head.
 * @param _file Name of file to save in.
 * @param format Format of saving value.
 * @param to_string Function that transforms ListData to string.
 */
void list_save_to_file(List *list, char *_file, char *format, char* (*to_string)(ListData));

/**
 * @brief Bubble sorting function of list.
 * 
 * @param head Pointer of list head.
 * @param comparator Function to compare two ListData elements.
 */
void list_bubble_sort(List *head, int (*comparator)(ListData, ListData));