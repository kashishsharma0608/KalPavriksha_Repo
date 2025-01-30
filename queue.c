#include <stdio.h>
#define MAX 100
int isEmpty(int top)
{
    return (top == -1);
}
void enqueue(int stack[], int *top, int value)
{
    if (*top == MAX - 1)
    {
        printf("Overflow! Queue is full.\n");
        return;
    }
    stack[++(*top)] = value;
    printf("Enqueued: %d\n", value);
}
int pop(int stack[], int *top)
{
    if (isEmpty(*top))
    {

        return -1;
    }
    return stack[(*top)--];
}
void dequeue(int stack[], int stack2[], int *top, int *top2)
{
    if (isEmpty(*top))
    {
        printf("Underflow!! Queue is empty.\n");
        return;
    }
    *top2 = -1;
    while (*top >= 0)
    {
        stack2[++(*top2)] = stack[(*top)--];
    }
    int poppedValue = pop(stack2, top2);
    printf("Dequeued value is: %d\n", poppedValue);
    while (*top2 >= 0)
    {
        stack[++(*top)] = stack2[(*top2)--];
    }
}

void peek(int stack[], int top)
{
    if (isEmpty(top))
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Peek of element is : %d", stack[0]);
}
void size(int stack[], int top)
{
    if (isEmpty(top))
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Size is :%d", top + 1);
}
int main()
{
    int stack[MAX], stack2[MAX], top = -1, top2 = -1;

    int numberOfOperations;

    printf("Enter the number of operations: ");
    scanf("%d", &numberOfOperations);

    for (int index = 0; index < numberOfOperations; index++)
    {
        int choice;
        printf("\n===== Queue Operations (Using Stack) =====\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Size\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int value;
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(stack, &top, value);
        }
        else if (choice == 2)
        {
            dequeue(stack, stack2, &top, &top2);
        }
        else if (choice == 3)
        {
            peek(stack, top);
        }
        else if (choice == 4)
        {
            size(stack, top);
        }
        else if (choice == 5)
        {
            printf("Exiting program...\n");
            return 0;
        }
        else
        {
            printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}
