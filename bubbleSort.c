/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int id;
    int power;
    struct node *next;
} node;
void createLinkedList(node **start, int id, int powerValue)
{
    node *newnNode = (node *)malloc(sizeof(node));
    newnNode->id = id;
    newnNode->power = powerValue;
    newnNode->next = NULL;
    if (*start == NULL)
    {
        *start = newnNode;
    }
    else
    {
        node *ptr = *start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newnNode;
    }
}
void display(node *start)
{
    if (start == NULL)
    {
        printf("List is empty");
        return;
    }
    while (start != NULL)
    {
        printf("%d->%d\n", start->id, start->power);
        start = start->next;
    }
}
int getLength(node *start)
{
    int length = 0;
    while (start != NULL)
    {
        length++;
        start = start->next;
    }
    return length;
}
node *sortThePowerNonIncreasing(node *start)
{
    int lengthOfList = getLength(start);
    int iterator = 0;
    int swapped;
    while (iterator < lengthOfList)
    {
        node *traverseNode = start;
        node *previousNode = start;
        swapped = 0;
        while (traverseNode->next != NULL)
        {
            node *pointer = traverseNode->next;
            if (traverseNode->power < pointer->power)
            {
                swapped = 1;
                if (traverseNode == start)
                {
                    traverseNode->next = pointer->next;
                    pointer->next = traverseNode;
                    previousNode = pointer;
                    start = previousNode;
                }
                else
                {
                    traverseNode->next = pointer->next;
                    pointer->next = traverseNode;
                    previousNode->next = pointer;
                    previousNode = pointer;
                }
                continue;
            }
            previousNode = traverseNode;
            traverseNode = traverseNode->next;
        }
        if (!swapped)
        {
            break;
        }
        iterator++;
    }
    return start;
}
void freeMemory(struct node **start)
{
    struct node *temp;
    while (*start != NULL)
    {
        temp = *start;
        *start = (*start)->next;
        free(temp);
    }
    *start = NULL;
}
int main()
{
    node *start = NULL;
    int numberOfHeroes;
    printf("\nEnter Number of Heroes:");
    scanf("%d", &numberOfHeroes);
    if (numberOfHeroes <= 0)
    {
        printf("Enter at least one hero.");
        return 0;
    }
    for (int iterator = 1; iterator <= numberOfHeroes; iterator++)
    {
        int powerValue;
        printf("\nEnter the power level of %d:", iterator);
        scanf("%d", &powerValue);
        createLinkedList(&start, iterator, powerValue);
    }
    if (numberOfHeroes == 1)
    {
        display(start);
        return 0;
    }
    printf("The List of Heroes Power Level Before Sorting:\n");
    display(start);
    start = sortThePowerNonIncreasing(start);
    printf("The List of Heroes Power Level After Sorting:\n");
    display(start);
    freeMemory(&start);
    return 0;
}