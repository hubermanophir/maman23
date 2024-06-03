#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int main(int argc, char *argv[])
{
    int i;
    char *file_name;
    Hashtable *hashTable = createHashtable();
    initHashTable(hashTable);

    if (argc == 1)
    {
        printf("No arguments provided\n");
        exit(0);
    }

    for (i = 1; i < argc; i++)
    {
        file_name = argv[i];
        add_integers_from_file(file_name, hashTable);
    }

    printHashtable(hashTable);
    destroyHashtable(hashTable);

    return 0;
}