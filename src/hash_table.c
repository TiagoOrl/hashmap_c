#include "hash_table.h"



size_t hash(char * str)
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


Node * createItem(char * data, uint index)
{
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = (char*)malloc(sizeof(char) * strSize(data) + sizeof(char));
    strcpy(newNode->data, data);
    newNode->i = index;

    return newNode;
}

size_t insert(Hashtable * table, char * data)
{
    size_t index = hash(data);
    Node * item = createItem(data, index);

    table->items[index] = item;

    return index;
}


Hashtable * createHashTable()
{
    Hashtable * newHashTable = (Hashtable *)malloc(sizeof(Hashtable));
    newHashTable->length = 0;
    newHashTable->items = (Node**) calloc(CAPACITY, sizeof(Node*));

    for (int i = 0; i < CAPACITY; i++)
        newHashTable->items[i] = NULL;

    return newHashTable;
}


size_t strSize(char * str)
{
    size_t i = 0;
    while (str[i] != '\0')
        i++;

    return i;
}