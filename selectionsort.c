#include <stdio.h>
#include <stdlib.h>

typedef struct evenOddSort {
    int data;
    struct evenOddSort *next;
} evenOddSort;

evenOddSort *createNode(int value) {
    evenOddSort *newNode = (evenOddSort *)malloc(sizeof(evenOddSort));
    if (!newNode) {
        printf("Allocation failed!");
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void createLinkedList(evenOddSort **head, int value) {
    evenOddSort *newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        evenOddSort *ptr = *head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
}

void display(evenOddSort *head) {
    if (head == NULL) {
        printf("List is empty");
        return;
    }
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void freeMemory(evenOddSort **start) {
    evenOddSort *temp;
    while (*start != NULL) {
        temp = *start;
        *start = (*start)->next;
        free(temp);
    }
    *start = NULL;
}
evenOddSort *sortList(evenOddSort *listHead, int isAscending) {
    if (listHead == NULL || listHead->next == NULL) {
        return listHead;
    }

    evenOddSort *sortedList = NULL;

    while (listHead != NULL) {
        evenOddSort *extremeNode = listHead;
        evenOddSort *previousExtremeNode = NULL;
        evenOddSort *currentNode = listHead;
        evenOddSort *previousNode = NULL;

        while (currentNode != NULL) {
            if ((isAscending && currentNode->data < extremeNode->data) || 
                (!isAscending && currentNode->data > extremeNode->data)) {
                extremeNode = currentNode;
                previousExtremeNode = previousNode;
            }
            previousNode = currentNode;
            currentNode = currentNode->next;
        }

        if (extremeNode == listHead) {
            listHead = listHead->next;
        } else {
            previousExtremeNode->next = extremeNode->next;
        }

        extremeNode->next = sortedList;
        sortedList = extremeNode;
    }
    evenOddSort *previousNode = NULL;
    evenOddSort *currentNode = sortedList;
    while (currentNode != NULL) {
        evenOddSort *nextNode = currentNode->next;
        currentNode->next = previousNode;
        previousNode = currentNode;
        currentNode = nextNode;
    }

    return previousNode;
}


evenOddSort *sortEvenOdd(evenOddSort *head) {
    evenOddSort *evenList = NULL, *evenListTail = NULL, *oddList = NULL, *oddListTail = NULL;
    evenOddSort *temp = head;
    
    while (temp != NULL) {
        if (temp->data % 2 == 0) {  // Even number
            if (evenList == NULL) {
                evenList = evenListTail = temp;
            } else {
                evenListTail->next = temp;
                evenListTail = temp;
            }
        } else {  // Odd number
            if (oddList == NULL) {
                oddList = oddListTail = temp;
            } else {
                oddListTail->next = temp;
                oddListTail = temp;
            }
        }
        temp = temp->next;
    }

    
    if (evenListTail != NULL) evenListTail->next = NULL;
    if (oddListTail != NULL) oddListTail->next = NULL;
    evenList = sortList(evenList, 1);  
    oddList = sortList(oddList, 0);  
    head = oddList;
    evenOddSort *temporary = head;
    
    while (temporary != NULL && temporary->next != NULL) {
        temporary = temporary->next;
    }
    
    if (temporary != NULL) {
        temporary->next = evenList;
    } else {
        head = evenList;
    }

    return head;
}

int main() {
    evenOddSort *start = NULL;
    int numberOfNodes;
    
    printf("Enter the number of nodes: ");
    scanf("%d", &numberOfNodes);
    
    if (numberOfNodes <= 0) {
        printf("Invalid Input");
        return 0;
    }

    for (int iterator = 0; iterator < numberOfNodes; iterator++) {
        int value;
        scanf("%d", &value);
        createLinkedList(&start, value);
    }

    if (numberOfNodes == 1) {
        display(start);
        return 0;
    }

    printf("Even and odd sorted list is :\n");
    start = sortEvenOdd(start);
    display(start);
    
    freeMemory(&start);
    return 0;
}
