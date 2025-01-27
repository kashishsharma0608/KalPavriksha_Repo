#include <stdio.h>
#include <stdlib.h>
typedef struct library
{
    char title[100];
    struct library *next;
} library;
int stringLength(char *string)
{
    int length = 0;
    while (string[length] != '\0')
    {
        length++;
    }
    return length;
}
int stringCompare(char *string1, char *string2)
{
    int iterator = 0;
    while (string1[iterator] != '\0' && string2[iterator] != '\0')
    {
        if (string1[iterator] < string2[iterator])
            return -1;
        if (string1[iterator] > string2[iterator])
            return 1;
        iterator++;
    }
    return string1[iterator] - string2[iterator];
}
void stringCopy(char destination[], char source[])
{
    int index = 0;
    while (source[index] != '\0')
    {
        destination[index] = source[index];
        index++;
    }
    destination[index] = '\0';
}
library *createNode(char *bookTitle)
{
    library *newNode = (library *)malloc(sizeof(library));
    if (!newNode)
    {
        printf("Allocation failed!");
        return NULL;
    }
    stringCopy(newNode->title, bookTitle);
    newNode->next = NULL;
    return newNode;
}

void createLinkedList(library **head, char *bookTitle)
{
    library *newNode = createNode(bookTitle);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        library *ptr = *head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
}

void display(library *head)
{
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    while (head != NULL)
    {
        printf("%s ", head->title);
        head = head->next;
    }
    printf("\n");
}

void freeMemory(library **start)
{
    library *temp;
    while (*start != NULL)
    {
        temp = *start;
        *start = (*start)->next;
        free(temp);
    }
    *start = NULL;
}
void splitList(library *start, library **bookListOne, library **bookListTwo)
{
    library *slow = start, *fast = start->next;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *bookListOne = start;
    *bookListTwo = slow->next;
    slow->next = NULL;
}

library *mergeSortedList(library *bookListOne, library *bookListTwo)
{
    if (bookListOne == NULL)
        return bookListTwo;
    if (bookListTwo == NULL)
        return bookListOne;

    library *bookLib = NULL;
    if (stringCompare(bookListOne->title, bookListTwo->title) <= 0)
    {
        bookLib = bookListOne;
        bookLib->next = mergeSortedList(bookListOne->next, bookListTwo);
    }
    else
    {
        bookLib = bookListTwo;
        bookLib->next = mergeSortedList(bookListOne, bookListTwo->next);
    }
    return bookLib;
}

void mergeSort(library **head)
{
    library *newHead = *head;
    if (newHead == NULL || newHead->next == NULL)
    {
        return;
    }

    library *bookListOne, *bookListTwo;
    splitList(newHead, &bookListOne, &bookListTwo);
    mergeSort(&bookListOne);
    mergeSort(&bookListTwo);
    *head = mergeSortedList(bookListOne, bookListTwo);
}

int main()
{
    library *start = NULL;
    int numberOfNodes;

    printf("Enter the number of nodes: ");
    scanf("%d", &numberOfNodes);

    if (numberOfNodes <= 0)
    {
        printf("Invalid Input");
        return 0;
    }

    for (int iterator = 0; iterator < numberOfNodes; iterator++)
    {
        char *bookTitle = (char *)malloc(100 * sizeof(char));
        scanf("%s", bookTitle);
        getchar();
        createLinkedList(&start, bookTitle);
    }

    if (numberOfNodes == 1)
    {
        display(start);
        return 0;
    }
    display(start);
    mergeSort(&start);
    display(start);
    freeMemory(&start);
    return 0;
}
