#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertNode(struct Node **start, int data, int position)
{
    struct Node *newNode = createNode(data);
    if (position == 1 || *start == NULL)
    {
        newNode->next = *start;
        *start = newNode;
        return;
    }
    struct Node *current = *start;
    while (position > 2 && current->next != NULL)
    {
        current = current->next;
        position--;
    }
    if (position > 2)
    {
        printf("Invalid Position");
        free(newNode);
        return;
    }
    newNode->next = current->next;
    current->next = newNode;
}
void deleteNode(struct Node **start, int position)
{
    if (*start == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }
    struct Node *temp;
    if (position == 1)
    {
        temp = *start;
        *start = (*start)->next;
        free(temp);
        return;
    }
    struct Node *current = *start;
    while (position > 2 && current->next != NULL)
    {
        current = current->next;
        position--;
    }

    if (current->next == NULL)
    {
        printf("Invalid position.\n");
        return;
    }

    temp = current->next;
    current->next = temp->next;
    free(temp);
}
void updateNode(struct Node *start, int position, int newData)
{
    if (start == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }

    struct Node *current = start;
    while (position > 1 && current != NULL)
    {
        current = current->next;
        position--;
    }

    if (current == NULL||position>1)
    {
        printf("Invalid position.\n");
        return;
    }

    current->data = newData;
}
void displayList(struct Node *start)
{
    if (start == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }

    printf("The Linked List is: ");
    while (start != NULL)
    {
        printf("%d -> ", start->data);
        start = start->next;
    }
    printf("NULL\n");
}
void freeList(struct Node **start)
{
    struct Node *current = *start;
    struct Node *nextNode;
    while (current != NULL)
    {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    *start = NULL;
}

int main()
{
    struct Node *start = NULL;
    int numberOfOperations;

    printf("Enter the number of operations you want to perform: ");
    scanf("%d", &numberOfOperations);
    if(!(numberOfOperations>=1&&numberOfOperations<=100)){
        printf("Wrong input for number of operation must be between 1 to 100.");
        return 0;
    }
    for (int iterator = 0; iterator < numberOfOperations; iterator++)
    {
        int choice;
        printf("\n1. Insert at beginning\n2. Insert at position\n3. Insert at end\n4. Delete at beginning\n5. Delete at end\n6. Delete at a position\n7. Update At a position.\n8. Display");
        printf("\nEnter a choice:   ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            int information;
            printf("\nEnter the data to be inserted");
            scanf("%d", &information);
            insertNode(&start, information, 1);
        }
        else if (choice == 2)
        {
            int position, information;
            printf("\nEnter the information to inserted:");
            scanf("%d", &information);
            printf("\nEnter the position:");
            scanf("%d", &position);
            insertNode(&start, information, position);
        }
        else if (choice == 3)
        {
            int information;
            printf("\nEnter the data to be inserted");
            scanf("%d", &information);
            int position = 1;
            struct Node *pointer = start;
            while (pointer != NULL)
            {
                position++;
                pointer = pointer->next;
            }
            insertNode(&start, information, position);
        }
        else if (choice == 4)
        {
            deleteNode(&start, 1);
        }
        else if (choice == 5)
        {
            int position = 0;
            struct Node *pointer = start;
            while (pointer != NULL)
            {
                position++;
                pointer = pointer->next;
            }
            deleteNode(&start, position);
        }
        else if (choice == 6)
        {
            int position;
            printf("\nEnter the Position to delete:");
            scanf("%d", &position);
            deleteNode(&start, position);
        }
        else if (choice == 7)
        {
            int position, newData;
            printf("\nEnter the position to be updated:");
            scanf("%d", &position);
            printf("\nEnter the new data:");
            scanf("%d", &newData);
            updateNode(start, position, newData);
        }
        else if (choice == 8)
        {
            displayList(start);
        }
        else
        {
            printf("Invalid Selection: Select between 1 to 8!");
        }
    }
    return 0;
}
