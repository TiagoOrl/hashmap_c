#ifndef H_LIST_MOD
#define H_LIST_MOD

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "node.h"

struct _list {
    Node * top;
    Node * bottom;
    unsigned int size;
};

typedef struct _list List;

void l_push(List * list, char * data);
void l_insertAt(List * l, int i, char * data);
Node * l_getAt(List * l, int i);
Node * l_getByVal(List * l, char * data);
void l_removeNode(List * l, Node * n);
void l_removeAt(List * list, int i);
void l_removeVal(List * l, int id);
char * l_dequeue(List * l);
char * l_pop(List * list);
void l_print(List * list);

List * l_newList();

Node * l_createNode();

#endif
