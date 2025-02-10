#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *createNode(int value) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (!newNode) {
        printf("Allocation failed!");
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void createDoublyLinkedList(struct node **head, int value) {
    struct node *newNode = createNode(value);
    if (!newNode) {
        return;
    }
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void display(struct node *head) {
    if (head == NULL) {
        printf("List is empty");
        return;
    }
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

void findMysticPair(struct node *head, int targetSum) {
    if (head == NULL || head->next == NULL) {
        printf("No Mystic Tree found");
        return;
    }
    
    struct node *tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    int found = 0;
    while (head != tail && tail->next != head) {
        int sum = head->data + tail->data;
        if (sum > targetSum) {
            tail = tail->prev;
        } else if (sum < targetSum) {
            head = head->next;
        } else {
            printf("Mystic Pair: (%d,%d)\n", head->data, tail->data);
            found = 1;
            head = head->next;
            tail = tail->prev;
        }
    }
    
    if (!found) {
        printf("No Mystic Tree found");
    }
}

void freeMemory(struct node **head) {
    struct node *current = *head;
    while (current != NULL) {
        struct node *nextNode = current->next;
        free(current);
        current = nextNode;
    }
    *head = NULL;
}

int main() {
    struct node *head = NULL;
    int numNodes;
    
    scanf("%d", &numNodes);
    if (numNodes <= 0) {
        printf("Enter a positive value or at least 1 node");
        return 0;
    }
    
    for (int i = 0; i < numNodes; i++) {
        int value;
        scanf("%d", &value);
        createDoublyLinkedList(&head, value);
    }

    if (numNodes == 1) {
        display(head);
        return 0;
    }

    int targetSum;
    scanf("%d", &targetSum);
    findMysticPair(head, targetSum);
    freeMemory(&head);
    
    return 0;
}
