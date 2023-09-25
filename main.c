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

    HashMap* table = hm_create();

    hm_insert(table, "a1234", "tiago orlando");
    hm_insert(table, "a4312", "jeff");
    hm_insert(table, "a4321", "Ronaldo R");
    hm_insert(table, "a2134", "Bill A.");
    hm_insert(table, "21a34", "0123516484");
    hm_insert(table, "abcd", "Noel Bandeire");
    hm_insert(table, "qwert123", "ABCDEF");
    hm_insert(table, "zzx", "TEST");
    hm_insert(table, "pp", "44$");
    hm_insert(table, "z421", " Pelé");
    hm_insert(table, "arm12", "TEST1");
    hm_insert(table, "arm21", "TEST2");
    hm_insert(table, "21arm", "TEST3");


    printf("%s\n", hm_get(table, "a1234"));
    printf("%s\n", hm_get(table, "a4312"));
    printf("%s\n", hm_get(table, "a4321"));
    printf("%s\n", hm_get(table, "a2134"));
    printf("%s\n", hm_get(table, "abcd"));
    printf("%s\n", hm_get(table, "qwert123"));
    printf("%s\n", hm_get(table, "zzx"));
    printf("%s\n", hm_get(table, "pp"));


    hm_remove(table, "a4321");
    
    

    nLines();
    
    hm_printAll(table);
    
    return 0;
}
