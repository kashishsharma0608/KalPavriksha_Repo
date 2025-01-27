#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *createNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (!newNode)
    {
        printf("Allocation failed!");
        return 0;
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void createDoublyLinkedList(struct node **head, int value)
{
    struct node *newNode = createNode(value);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct node *ptr = *head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
        newNode->prev = ptr;
    }
}
void display(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}
void findHarryMysticTree(struct node *head, int harryPower)
{
    if (head == NULL)
    {
        return;
    }
    struct node *tail = head;
    int found = 0;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    while (head != tail && tail->next != head)
    {
        int sum = head->data + tail->data;
        if (sum > harryPower)
        {
            tail = tail->prev;
        }
        else if (sum < harryPower)
        {
            head = head->next;
        }
        else if (sum == harryPower)
        {
            printf("Mystic Pair:");
            printf("(%d,%d)\n", head->data, tail->data);
            found = 1;
            head = head->next;
            tail = tail->prev;
        }
    }
    if (found == 0)
    {
        printf("No Mystic Tree found");
    }
}
void freeMemory(struct node **start)
{
    struct node *temp;
    while (*start != NULL)
    {
        temp = *start;
        free(temp);
        *start = (*start)->next;
    }
    *start = NULL;
}
int main()
{
    struct node *head = NULL;
    int numberOfMysticTrees;
    scanf("%d", &numberOfMysticTrees);
    if (numberOfMysticTrees <= 0)
    {
        printf("Enter the positive value or atleast 1 node");
        return 0;
    }
    for (int iterator = 0; iterator < numberOfMysticTrees; iterator++)
    {
        int value;
        scanf("%d", &value);
        createDoublyLinkedList(&head, value);
    }
    if (numberOfMysticTrees == 1)
    {
        display(head);
        return 0;
    }
    int harryPower;
    scanf("%d", &harryPower);
    findHarryMysticTree(head, harryPower);
    freeMemory(&head);
    return 0;
}
