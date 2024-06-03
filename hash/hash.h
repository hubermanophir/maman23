#define TABLE_SIZE 29
#define FILE_NAME_SIZE 100
typedef struct Node
{
    int value;
    int count;
    char file[FILE_NAME_SIZE];
    struct Node *next;
} Node;

typedef Node *Hashtable[TABLE_SIZE];

void add_integers_from_file(char *file_name, Hashtable *hashTable);
void printHashtable(Hashtable *hashTable);
Hashtable *createHashtable();
void initHashTable(Hashtable *hashTable);
void destroyHashtable(Hashtable *hashTable);
void insertToHashtable(Hashtable *hashTable, int value, char *file);