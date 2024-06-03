#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "hash.h"

void insertToHashtable(Hashtable *hashTable, int value, char *file);
void destroyHashtable(Hashtable *hashTable);
void add_integers_from_file(char *fileName, Hashtable *hashTable)
{
    int number;
    FILE *file;

    if (access(fileName, 0) == -1)
    {
        printf("%s does not exist\n", fileName);
        exit(0);
    }
    file = fopen(fileName, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        exit(0);
    }

    while (fscanf(file, "%d", &number) != EOF)
    {
        insertToHashtable(hashTable, number, fileName);
    }

    fclose(file);
}
