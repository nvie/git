#ifndef PATH_LIST_H
#define PATH_LIST_H

struct string_list_item {
	char *string;
	void *util;
};
struct string_list
{
	struct string_list_item *items;
	unsigned int nr, alloc;
	unsigned int strdup_strings:1;
};

void print_string_list(const char *text, const struct string_list *p);
void string_list_clear(struct string_list *list, int free_util);

/* Use this function to call a custom clear function on each util pointer */
/* The string associated with the util pointer is passed as the second argument */
typedef void (*string_list_clear_func_t)(void *p, const char *str);
void string_list_clear_func(struct string_list *list, string_list_clear_func_t clearfunc);

/* Use these functions only on sorted lists: */
int string_list_has_string(const struct string_list *list, const char *string);
int string_list_find_insert_index(const struct string_list *list, const char *string,
				  int negative_existing_index);
struct string_list_item *string_list_insert(const char *string, struct string_list *list);
struct string_list_item *string_list_insert_at_index(int insert_at,
						     const char *string, struct string_list *list);
struct string_list_item *string_list_lookup(const char *string, struct string_list *list);

/* Use these functions only on unsorted lists: */
struct string_list_item *string_list_append(const char *string, struct string_list *list);
void sort_string_list(struct string_list *list);
int unsorted_string_list_has_string(struct string_list *list, const char *string);

#endif /* PATH_LIST_H */
