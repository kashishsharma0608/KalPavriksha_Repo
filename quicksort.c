#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *createNode(int value) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void createLinkedList(struct node **head, int value) {
    struct node *newNode = createNode(value);
    if (!newNode) return;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct node *ptr = *head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
}

void display(struct node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void partition(struct node *head, struct node *pivot, struct node **smaller, struct node **larger) {
    *smaller = NULL;
    *larger = NULL;
    struct node *smallTail = NULL, *largeTail = NULL;

    while (head != NULL) {
        struct node *next = head->next;
        head->next = NULL;

        if (head->data < pivot->data) {
            if (*smaller == NULL) {
                *smaller = head;
                smallTail = head;
            } else {
                smallTail->next = head;
                smallTail = smallTail->next;
            }
        } else if (head != pivot) {
            if (*larger == NULL) {
                *larger = head;
                largeTail = head;
            } else {
                largeTail->next = head;
                largeTail = largeTail->next;
            }
        }
        head = next;
    }
}

int countNodes(struct node *head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

int findKthSmallestElement(struct node *head, int kthElement) {
    if (head == NULL) {
        return -1;
    }

    int totalNodes = countNodes(head);
    if (kthElement > totalNodes || kthElement <= 0) {
        printf("Invalid k value! Must be between 1 and %d.\n", totalNodes);
        return -1;
    }

    struct node *pivot = head, *smaller = NULL, *larger = NULL;
    partition(head, pivot, &smaller, &larger);

    int smallerCount = countNodes(smaller);

    if (smallerCount + 1 == kthElement) {
        return pivot->data;
    } else if (smallerCount >= kthElement) {
        return findKthSmallestElement(smaller, kthElement);
    } else {
        return findKthSmallestElement(larger, kthElement - smallerCount - 1);
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
    struct node *start = NULL;
    int listSize;

    printf("Enter the number of nodes: ");
    scanf("%d", &listSize);

    if (listSize <= 0) {
        printf("Enter a valid positive number of nodes.\n");
        return 0;
    }

    printf("Enter %d elements: ", listSize);
    for (int i = 0; i < listSize; i++) {
        int value;
        scanf("%d", &value);
        createLinkedList(&start, value);
    }

    int kthElement;
    printf("Enter the k value to find the kth-smallest element: ");
    scanf("%d", &kthElement);

    int result = findKthSmallestElement(start, kthElement);

    if (result != -1) {
        printf("The %dth-smallest element is: %d\n", kthElement, result);
    }

    freeMemory(&start);
    return 0;
}
