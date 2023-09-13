#ifndef HASH_MOD_H
#define HASH_MOD_H

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "node.h"

#define CAPACITY 5000

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
size_t strSize(char * str);

#endif