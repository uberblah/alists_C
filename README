# alists_C
alists for C!

0: Make a comparator for the key type (strings, in this example)
#include <stdbool.h>
#include <string.h>
bool cmpstrs(void* a, void* b)
{
    return !strcmp((char*)a, (char*)b);
}

1: Make an empty dictionary
#include "lists.h"
list* dict = NULL;

2: Set values in the dictionary
dict = alist_set(cmpstrs, dict, key, value);

3: Get values from the dictionary
void* result = alist_get(cmpstrs, dict, key);
