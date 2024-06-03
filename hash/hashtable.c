#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

Node *createNode(int value, char *file, int count);

Hashtable *createHashtable()
{
    Hashtable *hashTable = malloc(sizeof(Hashtable));
    if (hashTable == NULL)
    {
        perror("Failed to allocate memory for hash table");
        exit(EXIT_FAILURE);
    }
    return hashTable;
}

void initHashTable(Hashtable *hashTable)
{
    int i;
    for (i = 0; i < TABLE_SIZE; i++)
    {
        (*hashTable)[i] = NULL;
    }
}

void insertToHashtable(Hashtable *hashTable, int value, char *file)
{
    Node *newNode;
    Node *current = (*hashTable)[value];

    while (current)
    {
        if (strcmp(current->file, file) == 0)
        {
            current->count++;
            return;
        }
        current = current->next;
    }
    newNode = createNode(value, file, 1);
    newNode->next = (*hashTable)[value];
    (*hashTable)[value] = newNode;
}

void printHashtable(Hashtable *hashTable)
{
    int i;
    Node *current;
    for (i = 0; i < TABLE_SIZE; i++)
    {
        current = (*hashTable)[i];
        if (!current)
        {
            continue;
        }

        printf("%d appears in file ", i);
        while (current)
        {
            printf("%s - %d %s %s", current->file, current->count, current->count > 1 ? "times" : "time", current->next ? ", " : "");
            current = current->next;
        }
        printf("\n");
    }
}

void destroyHashtable(Hashtable *hashTable)
{
    int i;
    Node *current;
    Node *next;
    for (i = 0; i < TABLE_SIZE; i++)
    {
        current = (*hashTable)[i];
        while (current)
        {
            next = current->next;
            free(current);
            current = next;
        }
    }
    free(hashTable);
}