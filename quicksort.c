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
        printf("Allocation failed!");
        return 0;
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void createLinkedList(struct node **head, int value)
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
void partition(struct node *head, struct node *pivot, struct node **smaller, struct node **larger)
{
    *smaller = NULL;
    *larger = NULL;
    struct node *smallTail = NULL, *largeTail = NULL;
    while (head != NULL)
    {
        struct node *next = head->next;
        head->next = NULL;
        if (head->data < pivot->data)
        {
            if (*smaller == NULL)
            {
                *smaller = head;
                smallTail = head;
            }
            else
            {
                smallTail->next = head;
                smallTail = smallTail->next;
            }
        }
        else if (head != pivot)
        {
            if (*larger == NULL)
            {
                *larger = head;
                largeTail = head;
            }
            else
            {
                largeTail->next = head;
                largeTail = largeTail->next;
            }
        }
        head = next;
    }
}
int findKthSmallestElement(struct node *head, int kthElement)
{
    if (head == NULL)
    {
        return -1;
    }
    struct node *pivot = head, *smaller = NULL, *larger = NULL;
    partition(head, pivot, &smaller, &larger);
    int smallerCount = 0;
    struct node *temp = smaller;
    while (temp != NULL)
    {
        smallerCount++;
        temp = temp->next;
    }
    if (smallerCount + 1 == kthElement)
    {
        return pivot->data;
    }
    else if (smallerCount >= kthElement)
    {
        return findKthSmallestElement(smaller, kthElement);
    }
    else
    {
        return findKthSmallestElement(larger, kthElement - smallerCount - 1);
    }
}
int main()
{
    struct node *start = NULL;
    int numberOfNodes;
    scanf("%d", &numberOfNodes);
    if (numberOfNodes <= 0)
    {
        printf("Enter positive or at least 1 the number of nodes");
        return 0;
    }
    for (int iterator = 0; iterator < numberOfNodes; iterator++)
    {
        int value;
        scanf("%d", &value);
        createLinkedList(&start, value);
    }
    int kthElement;
    printf("Enter the kth-smallest element to find");
    scanf("%d", &kthElement);
    int result = findKthSmallestElement(start, kthElement);
    printf("The Kth-Smallest Element is : %d", result);
    return 0;
}