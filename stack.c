#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int isEmpty(int front)
{
    return (front == -1);
}
void push(int capacity, int queue[], int *front, int *rear, int value)
{
    if ((*rear + 1) % capacity == *front)
    {
        printf("Stack is full\n");
        return;
    }

    if (*front == -1)
    {
        *front = *rear = 0;
    }
    else
    {
        *rear = (*rear + 1) % capacity;
    }

    queue[*rear] = value;

    int size = (*rear - *front + capacity) % capacity + 1;
    for (int index = 0; index < size - 1; index++)
    {
        int temp = queue[*front];
        *front = (*front + 1) % capacity;
        *rear = (*rear + 1) % capacity;
        queue[*rear] = temp;
    }
}

int pop(int capacity, int queue[], int *front, int *rear)
{
    if (*front == -1)
    {
        printf("Stack is empty!\n");
        return -1;
    }

    int poppedElement = queue[*front];

    if (*front == *rear)
    {
        *front = -1;
        *rear = -1;
    }
    else
    {
        *front = (*front + 1) % capacity;
    }

    return poppedElement;
}

int top(int front, int queue[])
{
    if (isEmpty(front))
    {
        printf("Stack is empty!\n");
        return -1;
    }
    return queue[front];
}

int size(int front, int rear, int capacity)
{
    if (isEmpty(front))
    {
        return 0;
    }
    return (rear - front + capacity) % capacity + 1;
}

void display(int queue[], int front, int rear, int capacity)
{
    if (front == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    int index = front;
    while (1)
    {
        printf("%d ", queue[index]);
        if (index == rear)
            break;
        index = (index + 1) % capacity;
    }
    printf("\n");
}

int main()
{
    int queue[MAX];
    int front = -1, rear = -1, capacity;

    printf("Enter capacity: ");
    scanf("%d", &capacity);

    int numberOfOperations;
    printf("Enter the number of operations: ");
    scanf("%d", &numberOfOperations);

    for (int index = 0; index < numberOfOperations; index++)
    {
        int choice;
        printf("\n1. Push \n2. Pop \n3. Top \n4. Size \n5. Display \n0. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int value;
            printf("Enter the element to push: ");
            scanf("%d", &value);
            push(capacity, queue, &front, &rear, value);
        }
        else if (choice == 2)
        {
            int removed = pop(capacity, queue, &front, &rear);
            if (removed != -1)
            {
                printf("Popped element: %d\n", removed);
            }
        }
        else if (choice == 3)
        {
            int topElement = top(front, queue);
            if (topElement != -1)
            {
                printf("Top element: %d\n", topElement);
            }
        }
        else if (choice == 4)
        {
            printf("Size of stack: %d\n", size(front, rear, capacity));
        }
        else if (choice == 5)
        {
            display(queue, front, rear, capacity);
        }
        else if (choice == 0)
        {
            printf("Thank you!\n");
            return 0;
        }
        else
        {
            printf("Enter a valid choice (1 to 5) or 0 to exit.\n");
        }
    }

    return 0;
}
