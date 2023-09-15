#ifndef HASH_MOD_H
#define HASH_MOD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

#define CAPACITY 1000

typedef unsigned long ulong;
typedef unsigned int uint;

struct _hashmap 
{
    Item** items;
    uint length;
};

typedef struct _hashmap HashMap;

HashMap * hm_create();
Item * hm_createItem(char * key, char * data);
size_t hm_hash(char * key);
size_t hm_insert(HashMap * table, char * key, char * data);
size_t hm_delete(HashMap * table, char * key);
char * hm_get(HashMap * table, char * key);
char * hm_getByIndex(HashMap * table, uint i);
int hm_remove(HashMap * table, char * key);
size_t hm_removeByIndex(HashMap * table, uint index);
size_t hm_strSize(char * str);

void hm_printAll(HashMap * table);

#endif