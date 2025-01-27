#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *createNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (!newNode)
    {
        free(newNode);
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void createLinkedList(struct node **start, int value)
{
    struct node *newNode = createNode(value);
    if (*start == NULL)
    {
        *start = newNode;
    }
    else
    {
        struct node *ptr = *start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
}
void display(struct node *start)
{
    if (start == NULL)
    {
        printf("Empty list");
        return;
    }
    while (start != NULL)
    {
        printf("%d ", start->data);
        start = start->next;
    }
}
struct node *sortList(struct node *head, struct node *newSortedHead)
{
    if (newSortedHead == NULL || newSortedHead->data >= head->data)
    {
        head->next = newSortedHead;
        newSortedHead = head;
    }
    else
    {
        struct node *currentSorted = newSortedHead;
        while (currentSorted->next != NULL && currentSorted->next->data < head->data)
        {
            currentSorted = currentSorted->next;
        }
        head->next = currentSorted->next;
        currentSorted->next = head;
    }
    return newSortedHead;
}
struct node *insertionSort(struct node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    struct node *sorted = NULL, *current = head, *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        sorted = sortList(current, sorted);
        current = next;
    }
    return sorted;
}
struct node *kGroupWiseSort(struct node *head, int groupValue)
{
    if (head == NULL)
    {
        printf("list empty");
        return NULL;
    }
    struct node *dummy = createNode(0);
    dummy->next = head;
    struct node *groupStart = dummy;
    struct node *current = head;
    while (current != NULL)
    {
        struct node *prevGroupStart = current, *prevGroupEnd = current;
        for (int iterator = 1; iterator < groupValue && prevGroupEnd->next != NULL; iterator++)
        {

            prevGroupEnd = prevGroupEnd->next;
        }
        struct node *nextGroupStart = prevGroupEnd->next;
        prevGroupEnd->next = NULL;
        struct node *kSortedGroup = insertionSort(prevGroupStart);
        groupStart->next = kSortedGroup;
        while (groupStart->next != NULL)
        {
            groupStart = groupStart->next;
        }
        groupStart->next = nextGroupStart;
        current = nextGroupStart;
    }
    struct node *result = dummy->next;
    free(dummy);
    return result;
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
    struct node *start = NULL;
    int numberOfNodes;
    scanf("%d", &numberOfNodes);
    if (numberOfNodes <= 0)
    {
        printf("Enter a positive number or atleast 1 node");
        return 0;
    }
    for (int iterator = 0; iterator < numberOfNodes; iterator++)
    {
        int value;
        scanf("%d", &value);
        createLinkedList(&start, value);
    }
    if (numberOfNodes == 1)
    {
        display(start);
        return 0;
    }
    display(start);
    int groupValue;
    scanf("%d", &groupValue);
    if (groupValue <= 0)
    {
        printf("Value must be positive");
        return 0;
    }
    if (groupValue == 1)
    {
        display(start);
        return 0;
    }
    start = kGroupWiseSort(start, groupValue);
    printf("%d Wise Sorted List:\n", groupValue);
    display(start);
    freeMemory(&start);
    return 0;
}
