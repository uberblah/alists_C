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
	    return list_cons(d, orig);
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

void alist_free(list* alist, doer fcar, doer fcdr)
{
    while(alist)
    {
	dpair* data = alist->car;
	fcar(data->car);
	fcdr(data->cdr);
	free(data);
        list* old = alist;
	alist = alist->cdr;
	free(old);
    }
}

void list_free(list* lst, doer fitem)
{
    while(lst)
    {
	fitem(lst->car);
	list* old = lst;
	lst = lst->cdr;
	free(old);
    }
}

list* list_cons(void* data, list* lst)
{
  list* head = (list*)malloc(sizeof(list));
  head->car = data;
  head->cdr = lst;
  return head;
}

void list_iter(list* lst, doer doitem)
{
    list* curs = lst;
    while(curs)
    {
	doitem(curs->car);
	curs = curs->cdr;
    }
}
