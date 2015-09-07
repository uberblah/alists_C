#include "lists.h"

list* alist_set(comparator c, list* alist, void* key, void* value)
{
    list* orig = alist;
    
    while(true)
    {
	if(!alist)
	{
	    dpair* d = (dpair*)malloc(sizeof(dpair));
	    d->car = key;
	    d->cdr = value;
	    list* l = (list*)malloc(sizeof(list));
	    l->cdr = orig;
	    l->car = d;
	    return l;
	}
	dpair* data = (dpair*)alist->car;
	if(c(key, data->car))
	{
	    data->cdr = value;
	    return orig;
	}
	alist = alist->cdr;
    }
}

void* alist_get(comparator c, list* alist, void* key)
{
    while(alist)
    {
	dpair* data = (dpair*)alist->car;
	if(c(key, data->car))
	    return data->cdr;
	alist = alist->cdr;
    }
    return NULL;
}
