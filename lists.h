#include <stdlib.h>
#include <stdbool.h>

typedef bool(*comparator)(void*, void*);
typedef void(*doer)(void* tgt);

typedef struct list list;
struct list
{
    void* car;
    list* cdr;
};

typedef struct dpair dpair;
struct dpair
{
    void* car;
    void* cdr;
};

list* alist_set(comparator c, list* alist, void* key, void* value);
void* alist_get(comparator c, list* alist, void* key);
void alist_free(list* alist, doer fcar, doer fcdr);

void list_iter(list* lst, doer doitem);
void list_free(list* lst, doer fitem);
list* list_cons(void* data, list* lst);
