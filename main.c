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

    HashMap* table = hm_create();

    hm_insert(table, "1234", "tiago orlando");
    hm_insert(table, "12ss", "Noel Bandeire");
    hm_insert(table, "abcv", "0100111001010");
    hm_insert(table, "445D", "Hello World");

    // hm_remove(table, "abcv");

    char * f = hm_get(table, "abcv");
    if (f != NULL)
        printf("%s\n", f);

    hm_printAll(table);

    
    return 0;
}
