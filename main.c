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
    hm_insert(table, "4312", "jeff");
    hm_insert(table, "4321", "Ronaldo R");
    hm_insert(table, "2134", "Bill A.");
    hm_insert(table, "abcd", "Noel Bandeire");
    hm_insert(table, "qwert123", "ABCDEF");

    printf("%s\n", hm_get(table, "1234"));
    printf("%s\n", hm_get(table, "2134"));

    // hm_remove(table, "4312");
    // hm_remove(table, "4321");
    // hm_remove(table, "2134");

    nLines();
    
    hm_printAll(table);
    
    return 0;
}
