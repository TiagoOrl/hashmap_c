#ifndef HASH_MOD_H
#define HASH_MOD_H

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "node.h"

#define CAPACITY 500

typedef unsigned long ulong;
typedef unsigned int uint;

struct _hashtable 
{
    Node** items;
    uint length;
};

typedef struct _hashtable Hashtable;

Hashtable * ht_create();
Node * ht_createItem(char * data, uint index);
size_t ht_hash(char * str);
size_t ht_insert(Hashtable * table, char * data);
size_t ht_delete(Hashtable * table, char * data);
Node * ht_get(Hashtable * table, char * data);
Node * ht_getByIndex(Hashtable * table, uint i);
int ht_remove(Hashtable * table, char * data);
size_t ht_removeIndex(Hashtable * table, uint index);
size_t ht_strSize(char * str);

void ht_printAll(Hashtable * table);

#endif