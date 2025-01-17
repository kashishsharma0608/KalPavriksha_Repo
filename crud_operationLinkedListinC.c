#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *start = NULL;
void insertAtBeginning(int information)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = information;
    newnode->next = NULL;
    if (start == NULL)
    {
        start = newnode;
    }
    else
    {
        newnode->next = start;
        start = newnode;
    }
}
void insertionAtPosition(int information, int position)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = information;
    newnode->next = NULL;
    if (start == NULL)
    {
        start = newnode;
    }
    else
    {
        struct Node *ptr = start;
        int i;
        if (position == 1)
        {
            insertAtBeginning(information);
        }
        else
        {
            for (i = 1; i < position - 1; i++)
            {
                if (ptr == NULL)
                {
                    break;
                }
                ptr = ptr->next;
            }
            if (i == position - 1)
            {
                newnode->next = ptr->next;
                ptr->next = newnode;
            }
            else
            {
                printf("Invalid position");
            }
        }
    }
}
void insertAtEnd(int information)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = information;
    newnode->next = NULL;
    if (start == NULL)
    {
        start = newnode;
    }
    else
    {
        struct Node *ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newnode;
    }
}
void deleteAtBeginning()
{
    if (start == NULL)
    {
        printf("Linked list empty");
    }
    else
    {
        struct Node *ptr = start;
        start = ptr->next;
        free(ptr);
    }
}
void deleteAtEnd()
{
    if (start == NULL)
    {
        printf("linked list is empty");
    }
    else
    {
        struct Node *prev = NULL;
        struct Node *ptr = start;
        while (ptr->next != NULL)
        {
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = NULL;
        free(ptr);
    }
}
void deleteAtPosition(int position)
{
    if (start == NULL)
    {
        printf("linked list empty");
    }
    else
    {
        struct Node *ptr = start;
        if (position == 1 && start->next == NULL)
        {
            deleteAtBeginning();
        }
        else if (position == 1)
        {
            deleteAtBeginning();
        }
        else
        {
            int i;
            for (i = 1; i < position; i++)
            {
                if (ptr == NULL)
                {
                    break;
                }
                ptr = ptr->next;
            }
            if (i == position)
            {
                struct Node *current = NULL;
                current = ptr->next;
                ptr->next = current->next;
                free(current);
            }
            else
            {
                printf("Invalid");
            }
        }
    }
}
void updateAtPosition(int position, int newdata)
{
    if (start == NULL)
    {
        struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
        newnode->data = newdata;
        newnode->next = NULL;
        start = newnode;
    }
    else
    {
        int i;

        struct Node *ptr = start;
        for (i = 1; i < position; i++)
        {

            ptr = ptr->next;
        }
        if (i == position)
        {
            ptr->data = newdata;
        }
        else
        {
            printf("Invalid");
        }
    }
}
void display()
{
    printf("\nThe Linked List is : \t\t\t");
    struct Node *ptr = start;
    ptr = start;
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
int main()
{
    struct Node *start = NULL, *current = NULL;
    int num;
    printf("Enter the number of operation you want to perform:");
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        int choice;
        printf("\n1.Insert at beginning\n2. Insert at position\n3. Insert at end\n4. Delete at beginning\n5. Delete at end\n6. Delete at a position\n7. Update At a position.\n8. Display");
        printf("\nEnter a choice:   ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            int information;
            printf("\nEnter the data to be inserted");
            scanf("%d", &information);
            insertAtBeginning(information);
        }
        else if (choice == 2)
        {
            int position, information;
            printf("\nEnter the information to inserted:");
            scanf("%d", &information);
            printf("\nEnter the position:");
            scanf("%d", &position);
            insertionAtPosition(information, position);
        }
        else if (choice == 3)
        {
            int information;
            printf("\nEnter the data to be inserted");
            scanf("%d", &information);
            insertAtEnd(information);
        }
        else if (choice == 4)
        {
            deleteAtBeginning();
        }
        else if (choice == 5)
        {
            deleteAtEnd();
        }
        else if (choice == 6)
        {
            int position;
            printf("\nEnter the Position to delete:");
            scanf("%d", &position);
            deleteAtPosition(position);
        }
        else if (choice == 7)
        {
            int position, newdata;
            printf("\nEnter the position to be updated:");
            scanf("%d", &position);
            printf("\nEnter the new data:");
            scanf("%d", &newdata);
            updateAtPosition(position, newdata);
        }
        else if (choice == 8)
        {
            display();
        }
        else
        {
            printf("Invalid Selection:");
            return 0;
        }
    }
    return 0;
}