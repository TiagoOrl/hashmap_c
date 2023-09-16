#ifndef ITEM_MOD_H
#define ITEM_MOD_H

#include "g_list/list.h"

struct _item
{
    char * key;
    char * data;
    List * list;
};

typedef struct _item Item;


#endif