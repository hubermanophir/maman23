#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"


Node *createNode(int value, char *file, int count)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->value = value;
    newNode->count = count;
    strcpy(newNode->file, file);
    newNode->next = NULL;
    return newNode;
}
