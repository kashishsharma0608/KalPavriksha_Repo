#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int id;
    int power;
    struct node *next;
} node;

void createLinkedList(node **start, int id, int powerValue) {
    node *newNode = (node *)malloc(sizeof(node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->id = id;
    newNode->power = powerValue;
    newNode->next = NULL;

    if (*start == NULL) {
        *start = newNode;
    } else {
        node *traverseNode = *start;
        while (traverseNode->next != NULL) {
            traverseNode = traverseNode->next;
        }
        traverseNode->next = newNode;
    }
}

void display(node *start) {
    if (!start) {
        printf("List is empty\n");
        return;
    }
    while (start) {
        printf("%d -> %d\n", start->id, start->power);
        start = start->next;
    }
}

int getLength(node *start) {
    int length = 0;
    while (start) {
        length++;
        start = start->next;
    }
    return length;
}

node *sortThePowerNonIncreasing(node *start) {
    int swapped;
    node *currentNode, *lastSortedNode = NULL;

    if (!start) return start;

    do {
        swapped = 0;
        currentNode = start;
        node *previousNode = NULL;

        while (currentNode->next != lastSortedNode) {
            node *nextNode = currentNode->next;
            if (currentNode->power < nextNode->power) {
                swapped = 1;
                if (previousNode) {
                    previousNode->next = nextNode;
                } else {
                    start = nextNode;
                }
                currentNode->next = nextNode->next;
                nextNode->next = currentNode;
                previousNode = nextNode;
            } else {
                previousNode = currentNode;
                currentNode = currentNode->next;
            }
        }
        lastSortedNode = currentNode;
    } while (swapped);

    return start;
}

void freeMemory(node **start) {
    node *temp;
    while (*start) {
        temp = *start;
        *start = (*start)->next;
        free(temp);
    }
}

int main() {
    node *start = NULL;
    int numberOfHeroes;

    printf("\nEnter Number of Heroes: ");
    scanf("%d", &numberOfHeroes);

    if (numberOfHeroes <= 0) {
        printf("Enter at least one hero.\n");
        return 0;
    }

    for (int i = 1; i <= numberOfHeroes; i++) {
        int powerValue;
        printf("\nEnter the power level of hero %d: ", i);
        scanf("%d", &powerValue);
        createLinkedList(&start, i, powerValue);
    }

    printf("\nThe List of Heroes' Power Levels Before Sorting:\n");
    display(start);

    if (numberOfHeroes > 1) {
        start = sortThePowerNonIncreasing(start);
        printf("\nThe List of Heroes' Power Levels After Sorting:\n");
        display(start);
    }

    freeMemory(&start);
    return 0;
}
