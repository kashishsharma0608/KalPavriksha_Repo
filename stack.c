#include <stdio.h>
#define MAX 100

int isEmpty(int front) {
    return (front == -1);
}

void transferQueue(int queue1[], int queue2[], int *front1, int *rear1, int *front2, int *rear2) {
    *rear2 = -1;
    for (int i = *front1; i <= *rear1; i++) {
        queue2[++(*rear2)] = queue1[i];
    }
}

void push(int queue1[], int queue2[], int *front1, int *rear1, int *front2, int *rear2, int value) {
    if (isEmpty(*front1)) {
        *front1 = *rear1 = 0;
        queue1[*rear1] = value;
        printf("Pushed: %d\n", value);
        return;
    }

    transferQueue(queue1, queue2, front1, rear1, front2, rear2);

    *front1 = *rear1 = 0;
    queue1[*rear1] = value;

    for (int i = 0; i <= *rear2; i++) {
        queue1[++(*rear1)] = queue2[i];
    }
    printf("Pushed: %d\n", value);
}

void pop(int queue1[], int *front, int *rear) {
    if (isEmpty(*front)) {
        printf("Stack is empty! Cannot pop.\n");
        return;
    }
    printf("Popped: %d\n", queue1[(*front)++]);

    if (*front > *rear) {
        *front = *rear = -1;
    }
}

void peek(int queue1[], int front) {
    if (isEmpty(front)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Peek: %d\n", queue1[front]);
}

void size(int queue1[], int front, int rear) {
    if (isEmpty(front)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Size: %d\n", (rear - front + 1));
}

int main() {
    int queue1[MAX], queue2[MAX];
    int front1 = -1, rear1 = -1, front2 = -1, rear2 = -1;
    int numberOfOperations;

    printf("Enter the number of operations: ");
    scanf("%d", &numberOfOperations);

    for (int i = 0; i < numberOfOperations; i++) {
        int choice;
        printf("1. Push\n2. Pop\n3. Peek\n4. Size\n0. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int value;
            printf("Enter value: ");
            scanf("%d", &value);
            push(queue1, queue2, &front1, &rear1, &front2, &rear2, value);
        } else if (choice == 2) {
            pop(queue1, &front1, &rear1);
        } else if (choice == 3) {
            peek(queue1, front1);
        } else if (choice == 4) {
            size(queue1, front1, rear1);
        } else if (choice == 0) {
            return 0;
        } else {
            printf("Enter a valid option.\n");
        }
    }
    return 0;
}
