#define TABLE_SIZE 29
#define FILE_NAME_SIZE 100

typedef struct Node
{
    int value;
    int count;
    char file[FILE_NAME_SIZE];
    struct Node *next;
} Node;

typedef Node* Hashtable[TABLE_SIZE];