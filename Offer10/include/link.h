#ifndef __LIST_H
#define __LIST_H
#include <stdio.h>
#include <stdlib.h>
typedef struct _list_t
{
    int data;
    struct _list_t *next;
}list_t;
list_t * list_create(void);
int list_insert(list_t *list,int value);
int list_reverse(list_t * list);
int * list_reverse_array(list_t *list,int *arr_size);
void list_show(list_t *list);
#endif
