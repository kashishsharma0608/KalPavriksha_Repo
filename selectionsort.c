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

evenOddSort *sortOddList(evenOddSort *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    evenOddSort *sorted = NULL;

    while (head != NULL) {
        evenOddSort *minNode = head;
        evenOddSort *prevMin = NULL;
        evenOddSort *curr = head;
        evenOddSort *prev = NULL;
        while (curr != NULL) {
            if (curr->data > minNode->data) {
                minNode = curr;
                prevMin = prev;
            }
            prev = curr;
            curr = curr->next;
        }

        if (minNode == head) {
            head = head->next;
        } else {
            prevMin->next = minNode->next;
        }

        minNode->next = sorted;
        sorted = minNode;
    }

    evenOddSort *prev = NULL;
    evenOddSort *curr = sorted;
    while (curr != NULL) {
        evenOddSort *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

evenOddSort *sortEvenList(evenOddSort *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    evenOddSort *sorted = NULL;

    while (head != NULL) {
        evenOddSort *minNode = head;
        evenOddSort *prevMin = NULL;
        evenOddSort *curr = head;
        evenOddSort *prev = NULL;
        while (curr != NULL) {
            if (curr->data < minNode->data) {
                minNode = curr;
                prevMin = prev;
            }
            prev = curr;
            curr = curr->next;
        }

        if (minNode == head) {
            head = head->next;
        } else {
            prevMin->next = minNode->next;
        }

        minNode->next = sorted;
        sorted = minNode;
    }

    evenOddSort *prev = NULL;
    evenOddSort *curr = sorted;
    while (curr != NULL) {
        evenOddSort *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

evenOddSort *sortEvenOdd(evenOddSort *head) {
    evenOddSort *evenList = NULL, *evenListTail = NULL, *oddList = NULL, *oddListTail = NULL;
    evenOddSort *temp = head;
    
    while (temp != NULL) {
        if (temp->data % 2 == 0) {
            if (evenList == NULL) {
                evenList = temp;
                evenListTail = temp;
            } else {
                evenListTail->next = temp;
                evenListTail = evenListTail->next;
            }
        } else {
            if (oddList == NULL) {
                oddList = temp;
                oddListTail = temp;
            } else {
                oddListTail->next = temp;
                oddListTail = oddListTail->next;
            }
        }
        temp = temp->next;
    }
    if (evenListTail != NULL) evenListTail->next = NULL;
    if (oddListTail != NULL) oddListTail->next = NULL;

    evenList = sortEvenList(evenList);
    oddList = sortOddList(oddList);

    head = oddList;

    evenOddSort *temporary = head;
    while (temporary != NULL && temporary->next != NULL) {
        temporary = temporary->next;
    }
    
    if (temporary != NULL) {
        temporary->next = evenList;
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
