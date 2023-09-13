#ifndef HASH_MOD_H
#define HASH_MOD_H

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "node.h"

#define CAPACITY 120

typedef unsigned long ulong;
typedef unsigned int uint;

struct _hashtable 
{
    Node** items;
    uint length;
};

typedef struct _hashtable Hashtable;

Hashtable * createHashTable();
Node * createItem(char * data, uint index);
size_t hash(char * str);
size_t insert(Hashtable * table, char * data);
size_t delete(Hashtable * table, char * data);
Node * getByData(Hashtable * table, char * data);
Node * getByIndex(Hashtable * table, uint i);
int removeItem(Hashtable * table, char * data);
size_t removeIndex(Hashtable * table, uint index);
size_t strSize(char * str);

void printAll(Hashtable * table);

#endif