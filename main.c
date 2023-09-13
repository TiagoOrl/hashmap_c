#include <stdio.h>
#include <string.h>
#include "src/hash_table.h"

void nLines()
{
    printf("\n\n");
}


int main(int argc, char const *argv[])
{
    printf("\n\n\n-----\n");
    char * str = "hello";

    Hashtable* table = ht_create();

    ht_insert(table, str);
    ht_insert(table, "abc");
    ht_insert(table, "ees");
    ht_insert(table, "33");
    ht_insert(table, "-65s");

    ht_printAll(table);

    // Node * n = getByData(table, argv[1]);
    // if (n != NULL)
    //     printf("index: %d\t data: %s\n", n->i, n->data);

    nLines();

    ht_remove(table, "||");
    ht_remove(table, "33");
    ht_remove(table, "-65s");
    
    ht_printAll(table);

    
    return 0;
}
