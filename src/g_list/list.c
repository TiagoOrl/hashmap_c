#include "list.h"


Node * l_createNode(char * key, char * data)
{
    Node * node = (Node *)malloc(sizeof(Node));
    node->next = NULL;
    node->prev = NULL;
    node->data = (char *)malloc(strlen(data) * sizeof(char));
    node->key = (char *)malloc(strlen(key) * sizeof(char));
    node->i = -1;

    strcpy(node->data, data);
    strcpy(node->key, key);

    return node;
}

void l_push(List * list, char * data, char * key)
{
    Node * newNode = l_createNode(key, data);

    newNode->i = list->size;

    if (list->top == NULL || list->size == 0)
    {
        list->top = newNode;
        list->bottom = newNode;
    }
    else 
    {
        list->top->prev = newNode;
        newNode->next = list->top;
        list->top = newNode;
    }
    list->size++;
}

char * l_pop(List * list)
{
    if (list->top == NULL)
        return NULL;
    
    Node * topNode = list->top;
    char * val = (char *)malloc(strlen(list->top->data) * sizeof(char));
    
    strcpy(val, topNode->data);
    l_cleanupNode(topNode);

    list->top = list->top->next;
    if (list->top == NULL)
        list->bottom = NULL;
    else
        list->top->prev = NULL;

    list->size--;
    free(topNode);

    return val;
}

Node * l_getAt(List * list, int i)
{    
    Node * it = NULL;

    if (i < 0 || list == NULL)
        return NULL;

    it = list->top;

    while (it != NULL)
    {
        if (it->i == i)
            return it;
        it = it->next;
    }

    return it;
}

Node * l_getByKey(List * list, char * key)
{
    Node * it = NULL;

    if (list == NULL)
        return NULL;

    it = list->top;

    while (it != NULL)
    {
        if (strcmp(it->key, key) == 0)
            return it;
        it = it->next;
    }

    return it;
}


void l_removeNode(List * list, Node * found)
{
    if (found == NULL)
        return;


    if (found->prev == NULL && found->next == NULL)
    {
        l_pop(list);
        return;
    }

    // top node
    if (found->prev == NULL)
    {
        Node * nextSubs = found->next;
        nextSubs->prev = NULL;
        list->top = nextSubs;
        list->size--;

        l_cleanupNode(found);
        free(found);
        return;
    }

    // bottom node
    if (found->next == NULL)
    {
        Node * prevSubs = found->prev;
        Node * it = prevSubs;
        prevSubs->next = NULL;
        list->bottom = prevSubs;

        list->size--;

        while(it != NULL)
        {
            it->i--;
            it = it->prev;
        }

        l_cleanupNode(found);
        free(found);
        return;
    }

    Node * subs = found->prev;
    Node * it = subs;

    found->next->prev = subs;
    subs->next = found->next;
    list->size--;

    while (it != NULL)
    {
        it->i--;
        it = it->prev;
    }

    l_cleanupNode(found);
    free(found);
    return;
}

void l_removeKey(List * list, char * key)
{
    if (list->size < 1)
        return;

    Node * found = NULL;

    found = l_getByKey(list, key);
    l_removeNode(list, found);
}

void l_removeAt(List * list, int i)
{

    if (
        list->size < 1 || 
        list->top == NULL || 
        i >= list->size ||
        i < 0
    )
        return;



    Node * found = NULL;

    if (i == 0)
        found = list->bottom;
    else if (i == list->size - 1)
        found = list->top;
    else
        found = l_getAt(list, i);

    l_removeNode(list, found);
}

/**
 * removes from bottom/first position
*/
char * l_dequeue(List * list)
{
    if (
        list == NULL || 
        list->bottom == NULL || 
        list->size < 1
    )
        return NULL;

    Node * oldBottom = list->bottom;
    char * val = (char *)malloc(strlen(oldBottom->data) * sizeof(char));
    strcpy(val, oldBottom->data);
    list->bottom = oldBottom->prev;

    l_cleanupNode(oldBottom);

    if (list->bottom != NULL)
        list->bottom->next = NULL;
    else
        list->top = NULL;

    list->size--;

    Node * it = list->bottom;
    while (it != NULL)
    {
        it->i--;
        it = it->prev;
    }

    free(oldBottom);
    return val;
}

List * l_newList()
{
    List * list = (List *)malloc(sizeof(List));

    list->size = 0;
    list->top = NULL;
    list->bottom = NULL;

    return list;
}

void l_print(List * list)
{
    Node * it = list->top;

    printf("\nstack size: %d\n", list->size);

    printf("Printing all items: \n\n");

    while (it != NULL && list->size > 0)
    {
        printf("(%s)\tdata: %s", it->key, it->data);
        if (it->prev != NULL)
            printf("\t prev: (%s)\n", it->prev->key);
        else
            printf("\n");
        it = it->next;
    }

    printf("\n");

    if (list->top != NULL)
        printf("top:\t(%s)\n", list->top->data);
    
    if (list->bottom != NULL)
        printf("bottom:\t(%s)\n\n", list->bottom->data);
}

void l_cleanupNode(Node * n)
{
    free(n->key);
    free(n->data);
    n->key = NULL;
    n->data = NULL;
}