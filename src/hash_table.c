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
    table->length++;

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

Node * getByData(Hashtable * table, char * data)
{
    if (table == NULL)
        return NULL;
    
    return table->items[hash(data)];
}

Node * getByIndex(Hashtable * table, uint i)
{
    if (table == NULL || i >= CAPACITY)
        return NULL;

    return table->items[i];
}

int removeItem(Hashtable * table, char * data)
{
    if (table ==  NULL)
        return -1;

    size_t index = hash(data);

    if (table->items[index] == NULL)
        return -1;
    
    free(table->items[index]->data);
    table->items[index]->data = NULL;
    free(table->items[index]);
    table->items[index] = NULL;

    table->length--;

    return index;
}

void printAll(Hashtable * table)
{
    printf("length: %d\n", table->length);

    if (table->length < 1)
        return;

    for (int i = 0; i < CAPACITY; i++)
    {
        if (table->items[i] != NULL)
            printf("i: %d data: %s \n", table->items[i]->i, table->items[i]->data);
    }
}