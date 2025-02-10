#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10
typedef struct hashNode
{
    int key;
    int value;
    struct hashNode *next;
} hashNode;

typedef struct hashMap
{
    int numberOfElements;
    hashNode **table;
} hashMap;

int hashFunction(int key)
{
    return key % TABLE_SIZE;
}

void initializeHashMap(hashMap *map)
{
    map->numberOfElements = 0;
    map->table = (hashNode **)malloc(TABLE_SIZE * sizeof(hashNode *));
    for (int index = 0; index < TABLE_SIZE; index++)
    {
        map->table[index] = NULL;
    }
}

hashNode *createNode(int key, int value)
{
    hashNode *newNode = (hashNode *)malloc(sizeof(hashNode));
    if(!newNode){
        printf("Memory Allocation Failed.\n");
        return NULL;
    }
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void insert(hashMap *map, int key, int value)
{
    int index = hashFunction(key);
    hashNode *current = map->table[index];
    while (current != NULL)
    {
        if (current->key == key)
        {
            current->value = value;
            printf("Updated key %d with value %d.\n", key, value);
            return;
        }
        current = current->next;
    }
    hashNode *newNode = createNode(key, value);
    newNode->next = map->table[index];
    map->table[index] = newNode;
    map->numberOfElements++;
    printf("Inserted key %d with value %d.\n", key, value);
}

void removeKey(hashMap *map, int key)
{
    int index = hashFunction(key);
    hashNode *current = map->table[index];
    hashNode *previous = NULL;

    while (current != NULL)
    {
        if (current->key == key)
        {
            if (previous == NULL)
            {
                map->table[index] = current->next;
            }
            else
            {
                previous->next = current->next;
            }
            free(current);
            printf("Key %d deleted successfully.\n", key);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Key %d not found.\n", key);
}

int search(hashMap *map, int key)
{
    int index = hashFunction(key);
    hashNode *current = map->table[index];

    while (current != NULL)
    {
        if (current->key == key)
        {
            return current->value;
        }
        current = current->next;
    }
    return -1;
}

void display(hashMap *map)
{
    for (int index = 0; index < TABLE_SIZE; index++)
    {
        printf("Index %d: ", index + 1);
        hashNode *current = map->table[index];
        while (current != NULL)
        {
            printf("(%d, %d) -> ", current->key, current->value);
            current = current->next;
        }
        printf("NULL\n");
    }
}

void freeMemory(hashMap *map)
{
    for (int index = 0; index < TABLE_SIZE; index++)
    {
        hashNode *current = map->table[index];
        while (current != NULL)
        {
            hashNode *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(map->table);
}

int main()
{
    hashMap *map = (hashMap *)malloc(sizeof(hashMap));
    initializeHashMap(map);

    printf("========== HASH MAP ==========\n");

    while (1)
    {
        int choice;
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int key, value;
            printf("Enter Key: ");
            scanf("%d", &key);
            while (key < 0)
            {
                printf("Enter non-negative key : ");
                scanf("%d", &key);
            }
            printf("Enter Value: ");
            scanf("%d", &value);
            while (value < 0)
            {
                printf("Enter non-negative value : ");
                scanf("%d", &value);
            }
            insert(map, key, value);
        }
        else if (choice == 2)
        {
            int keyToDelete;
            printf("Enter the key to delete: ");
            scanf("%d", &keyToDelete);
            removeKey(map, keyToDelete);
        }
        else if (choice == 3)
        {
            int keyToSearch;
            printf("Enter the key to search: ");
            scanf("%d", &keyToSearch);
            int result = search(map, keyToSearch);
            if (result == -1)
            {
                printf("Key %d not found.\n", keyToSearch);
            }
            else
            {
                printf("Key %d found with value: %d\n", keyToSearch, result);
            }
        }
        else if (choice == 4)
        {
            display(map);
        }
        else if (choice == 5)
        {
            printf("Exiting... Thank you!\n");
            freeMemory(map);
            free(map);
            return 0;
        }
        else
        {
            printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    }
    return 0;
}