#include <stdio.h>
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
}

int pop(int capacity, int queue[], int *front, int *rear)
{
    if (*front == -1)
    {
        printf("Stack is empty!\n");
        return -1;
    }

    int poppedElement = queue[*rear];

    if (*front == *rear)
    {
        *front = -1;
        *rear = -1;
    }
    else if (*rear == 0)
    {
        *rear = capacity - 1;
    }
    else
    {
        (*rear)--;
    }

    return poppedElement;
}

int top(int rear, int queue[])
{
    if (rear == -1)
    {
        printf("Stack is empty!\n");
        return -1;
    }
    return queue[rear];
}

int size(int front, int rear, int capacity)
{
    if (front == -1)
        return 0;
    return (rear - front + capacity) % capacity + 1;
}

void display(int queue[], int front, int rear, int capacity)
{
    if (front == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack (top to bottom): ");
    int index = rear;
    while (1)
    {
        printf("%d ", queue[index]);
        if (index == front)
            break;
        index = (index - 1 + capacity) % capacity;
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
    while (numberOfOperations < 0)
    {
        printf("Enter a non-negative number Of Operations:\n");
        scanf("%d", &numberOfOperations);
    }
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
            int topElement = top(rear, queue);
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
