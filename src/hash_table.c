#include "hash_table.h"



size_t ht_hash(char * str)
{
    size_t i = 0;
    uint j = 0;

    while (str[j] != '\0')
    {
        i += str[j];
        j++;
    }

    return i % CAPACITY;
}


Node * ht_createItem(char * data, uint index)
{
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = (char*)malloc(sizeof(char) * ht_strSize(data) + sizeof(char));
    strcpy(newNode->data, data);
    newNode->i = index;

    return newNode;
}

size_t ht_insert(Hashtable * table, char * data)
{
    size_t index = ht_hash(data);
    Node * item = ht_createItem(data, index);

    table->items[index] = item;
    table->length++;

    return index;
}


Hashtable * ht_create()
{
    Hashtable * newHashTable = (Hashtable *)malloc(sizeof(Hashtable));
    newHashTable->length = 0;
    newHashTable->items = (Node**) calloc(CAPACITY, sizeof(Node*));

    for (int i = 0; i < CAPACITY; i++)
        newHashTable->items[i] = NULL;

    return newHashTable;
}


size_t ht_strSize(char * str)
{
    size_t i = 0;
    while (str[i] != '\0')
        i++;

    return i;
}

Node * ht_get(Hashtable * table, char * data)
{
    if (table == NULL)
        return NULL;
    
    return table->items[ht_hash(data)];
}

Node * ht_getByIndex(Hashtable * table, uint i)
{
    if (table == NULL || i >= CAPACITY)
        return NULL;

    return table->items[i];
}

int ht_remove(Hashtable * table, char * data)
{
    if (table ==  NULL)
        return -1;

    size_t index = ht_hash(data);

    if (table->items[index] == NULL)
        return -1;
    
    free(table->items[index]->data);
    table->items[index]->data = NULL;
    free(table->items[index]);
    table->items[index] = NULL;

    table->length--;

    return index;
}

void ht_printAll(Hashtable * table)
{
    printf("length: %d\n", table->length);

    if (table == NULL || table->length < 1)
        return;

    for (int i = 0; i < CAPACITY; i++)
    {
        if (table->items[i] != NULL)
            printf("i: %d data: %s \n", table->items[i]->i, table->items[i]->data);
    }
}