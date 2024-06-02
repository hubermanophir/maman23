#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

void initHashTable(Hashtable *hashTable)
{
    int i;
    for (i = 0; i < TABLE_SIZE; i++)
    {
        *hashTable[i] = NULL;
    }
}