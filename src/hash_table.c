#include "hash_table.h"



size_t hm_hash(char * str)
{
    size_t i = 0;
    uint j = 0;

    while (str[j] != '\0')
    {
        i += str[j] * 127 ^ j;
        j++;
    }

    return i % CAPACITY;
}


Item * hm_createItem(char * key, char * data)
{
    Item * newNode = (Item *)malloc(sizeof(Item));
    newNode->key = (char*)malloc(sizeof(char) * hm_strSize(key) + sizeof(char));
    newNode->data = (char*)malloc(sizeof(char) * hm_strSize(data) + sizeof(char));
    newNode->list = NULL;
    strcpy(newNode->data, data);
    strcpy(newNode->key, key);

    return newNode;
}

size_t hm_insert(HashMap * table, char * key, char * data)
{
    size_t index = hm_hash(key);

    if (hm_get(table, key) != NULL)
        return -1;

    if (table->items[index] == NULL)
    {
        Item * item = hm_createItem(key, data);
        table->items[index] = item;
    }
    else 
    {
        if (table->items[index]->list == NULL)
            table->items[index]->list = l_newList();
        
        l_push(table->items[index]->list, data, key);
    }

    table->length++;

    return index;
}


HashMap * hm_create()
{
    HashMap * newHashTable = (HashMap *)malloc(sizeof(HashMap));
    newHashTable->length = 0;
    newHashTable->items = (Item**) calloc(CAPACITY, sizeof(Item*));

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
    Item * found = table->items[hm_hash(key)];

    if (found != NULL)
    {
        if (strcmp(found->key, key) == 0)
            return found->data;
        else 
        {
            Node * l_foundNode = l_getByKey(found->list, key);
            if (l_foundNode != NULL)
                return l_foundNode->data;
        }
    }
        

    return NULL;
}


int hm_remove(HashMap * table, char * key)
{
    if (table ==  NULL)
        return -1;

    size_t hIndex = hm_hash(key);

    if (table->items[hIndex] == NULL)
        return -1;
    
    if (table->items[hIndex]->list == NULL)
    {
        if (strcmp(table->items[hIndex]->key, key) != 0)
            return -1;
        
        free(table->items[hIndex]->data);
        free(table->items[hIndex]->key);
        table->items[hIndex]->key = NULL;
        table->items[hIndex]->data = NULL;
        free(table->items[hIndex]);
        table->items[hIndex] = NULL;
    } 
    
    else 
    {
        if (strcmp(table->items[hIndex]->key, key) == 0)
        {
            free(table->items[hIndex]->data);
            free(table->items[hIndex]->key);
            table->items[hIndex]->key = NULL;
            table->items[hIndex]->data = NULL;
        }
        else 
        {
            l_removeKey(table->items[hIndex]->list, key);
        }

        if (table->items[hIndex]->list->size < 1)
        {
            free(table->items[hIndex]->list);
            table->items[hIndex]->list = NULL;
        }
            
    }

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
        {
            printf("key: %s data: %s ", table->items[i]->key, table->items[i]->data);
            if(table->items[i]->list != NULL)
            {
                Node * it = table->items[i]->list->top;
                while (it != NULL)
                {
                    printf("-> (%s)%s ", it->key, it->data);
                    it = it->next;
                }
            }
            printf("\n");
        }
    }
}