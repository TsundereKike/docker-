#include "link.h"
list_t * list_create(void)
{
    list_t *Head;
    Head = (list_t *)malloc(sizeof(list_t));
    if(Head==NULL)
    {
        printf("malloc failed!\r\n");
        return NULL;        
    }
    Head->data = 0;
    Head->next = NULL;
    return Head;
}
int list_insert(list_t *list,int value)
{
    list_t *new_node;
    list_t *p;
    if(list==NULL)
    {
        printf("list is NULL!\r\n");
        return -1;
    }
    new_node = (list_t *)malloc(sizeof(list_t));
    if(new_node==NULL)
    {
        printf("malloc failed!\r\n");
        return -1;
    }
    new_node->data = value;
    new_node->next = NULL;

    p = list;
    while(p->next)
    {
        p = p->next;
    }
    p->next = new_node;
    return 0;
}
int list_reverse(list_t * list)
{
    list_t *p,*q;
    if(list==NULL || list->next==NULL || list->next->next==NULL)/*链表为空或者只有一个节点*/
    {
        printf("list is NULL!\r\n");
        return -1;
    }
    p = list->next->next;
    list->next->next = NULL;

    while(p)
    {
        q = p;
        p = p->next;

        q->next = list->next;
        list->next = q;
    }
    return 0;
}
int * list_reverse_array(list_t *list,int *arr_size)
{
    int cnt = 0;
    int i = 0;
    list_t *p;
    if(list==NULL || list->next == NULL)
    {
        printf("list is NULL!\r\n");
        return NULL;
    }
    p = list;
    while(p->next)
    {
        cnt++;
        printf("cnt=%d\r\n",cnt);
        p = p->next;
    }
    *arr_size = cnt;
    int *ret_arr = (int *)malloc(sizeof(int)*cnt);
    if(ret_arr==NULL)
    {
        printf("malloc failed!\r\n");
        return NULL;
    }
    list_reverse(list);/*链表反转*/
    list_show(list);
    p = list;
    while(p->next)
    {
      *(ret_arr+i) =  p->next->data;
      p = p->next;
      i++; 
    }
    return ret_arr;
}
void list_show(list_t *list)
{
    list_t *p;
    if(list==NULL)
    {
        printf("list is NULL!\r\n");
        return;
    }
    p = list;
    while(p->next)
    {
        printf("%d ",p->next->data);
        p = p->next; 
    }
    printf("\r\n");
}
