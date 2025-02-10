#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *createNode(int value) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void createLinkedList(struct node **start, int value) {
    struct node *newNode = createNode(value);
    if (*start == NULL) {
        *start = newNode;
    } else {
        struct node *ptr = *start;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
}

void display(struct node *start) {
    if (start == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (start != NULL) {
        printf("%d ", start->data);
        start = start->next;
    }
    printf("\n");
}

struct node *sortList(struct node *head, struct node *newSortedHead) {
    if (newSortedHead == NULL || newSortedHead->data >= head->data) {
        head->next = newSortedHead;
        newSortedHead = head;
    } else {
        struct node *currentSorted = newSortedHead;
        while (currentSorted->next != NULL && currentSorted->next->data < head->data) {
            currentSorted = currentSorted->next;
        }
        head->next = currentSorted->next;
        currentSorted->next = head;
    }
    return newSortedHead;
}

struct node *insertionSort(struct node *head) {
    struct node *sorted = NULL, *current = head, *next;
    while (current != NULL) {
        next = current->next;
        sorted = sortList(current, sorted);
        current = next;
    }
    return sorted;
}

struct node *kGroupWiseSort(struct node *head, int groupValue) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return NULL;
    }
    struct node *dummy = createNode(0);
    dummy->next = head;
    struct node *groupStart = dummy;
    struct node *current = head;
    while (current != NULL) {
        struct node *prevGroupStart = current, *prevGroupEnd = current;
        for (int iterator = 1; iterator < groupValue && prevGroupEnd->next != NULL; iterator++) {
            prevGroupEnd = prevGroupEnd->next;
        }
        struct node *nextGroupStart = prevGroupEnd->next;
        prevGroupEnd->next = NULL;
        struct node *kSortedGroup = insertionSort(prevGroupStart);
        groupStart->next = kSortedGroup;
        while (groupStart->next != NULL) {
            groupStart = groupStart->next;
        }
        groupStart->next = nextGroupStart;
        current = nextGroupStart;
    }
    struct node *result = dummy->next;
    free(dummy);
    return result;
}

void freeMemory(struct node **start) {
    struct node *temp;
    while (*start != NULL) {
        temp = *start;
        *start = (*start)->next;
        free(temp);
    }
    printf("Memory has been freed.\n");
}

int main() {
    struct node *start = NULL;
    int numberOfNodes;
    printf("Enter the number of nodes: ");
    scanf("%d", &numberOfNodes);
    
    if (numberOfNodes <= 0) {
        printf("Please enter a positive number greater than zero.\n");
        return 0;
    }
    
    printf("Enter %d values: ", numberOfNodes);
    for (int iterator = 0; iterator < numberOfNodes; iterator++) {
        int value;
        scanf("%d", &value);
        createLinkedList(&start, value);
    }
    
    display(start);
    
    int groupValue;
    printf("Enter the group size for sorting: ");
    scanf("%d", &groupValue);
    
    if (groupValue <= 0) {
        printf("Group size must be a positive integer.\n");
        return 0;
    }
    
    if (groupValue == 1) {
        printf("Group size is 1, so the list remains unchanged.\n");
        display(start);
        return 0;
    }
    
    start = kGroupWiseSort(start, groupValue);
    printf("%d-wise Sorted List:\n", groupValue);
    display(start);
    
    freeMemory(&start);
    return 0;
}
