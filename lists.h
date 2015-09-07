#include <stdlib.h>
#include <stdbool.h>

typedef bool(*comparator)(void*, void*);

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
