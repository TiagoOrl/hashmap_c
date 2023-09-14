#include "hash_table.h"



size_t hm_hash(char * str)
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


Node * hm_createItem(char * key, char * data)
{
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->key = (char*)malloc(sizeof(char) * hm_strSize(key) + sizeof(char));
    newNode->data = (char*)malloc(sizeof(char) * hm_strSize(data) + sizeof(char));
    strcpy(newNode->data, data);
    strcpy(newNode->key, key);

    return newNode;
}

size_t hm_insert(HashMap * table, char * key, char * data)
{
    size_t index = hm_hash(key);
    Node * item = hm_createItem(key, data);

    table->items[index] = item;
    table->length++;

    return index;
}


HashMap * hm_create()
{
    HashMap * newHashTable = (HashMap *)malloc(sizeof(HashMap));
    newHashTable->length = 0;
    newHashTable->items = (Node**) calloc(CAPACITY, sizeof(Node*));

    for (int i = 0; i < CAPACITY; i++)
        newHashTable->items[i] = NULL;

    return newHashTable;
}


size_t hm_strSize(char * str)
{
    size_t i = 0;
    while (str[i] != '\0')
        i++;

    return i;
}

char * hm_get(HashMap * table, char * key)
{
    if (table == NULL)
        return NULL;
    Node * found = table->items[hm_hash(key)];

    if (found != NULL)
        return found->data;

    return NULL;
}

char * hm_getByIndex(HashMap * table, uint i)
{
    if (table == NULL || i >= CAPACITY || i < 0)
        return NULL;

    if (table->items[i] != NULL)
        return table->items[i]->data;

    return NULL;
}

int hm_remove(HashMap * table, char * key)
{
    if (table ==  NULL)
        return -1;

    size_t hIndex = hm_hash(key);

    if (table->items[hIndex] == NULL)
        return -1;
    
    free(table->items[hIndex]->data);
    free(table->items[hIndex]->key);
    table->items[hIndex]->key = NULL;
    table->items[hIndex]->data = NULL;
    free(table->items[hIndex]);
    table->items[hIndex] = NULL;

    table->length--;

    return hIndex;
}

void hm_printAll(HashMap * table)
{
    printf("length: %d\n", table->length);

    if (table == NULL || table->length < 1)
        return;

    for (int i = 0; i < CAPACITY; i++)
    {
        if (table->items[i] != NULL)
            printf("key: %s data: %s \n", table->items[i]->key, table->items[i]->data);
    }
}