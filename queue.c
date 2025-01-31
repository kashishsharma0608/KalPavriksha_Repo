
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
void dequeue(int stack[], int *top)
{
    if (isEmpty(*top))
    {
        printf("Underflow!!");
        return;
    }
    int temporary[MAX], temporaryIndex = 0;
    while (*top > 0)
    {
        temporary[temporaryIndex++] = stack[(*top)--];
    }
    printf("Dequeued element is: %d\n", stack[(*top)--]);
    for (int index = temporaryIndex - 1; index >= 0; index--)
    {
        stack[++(*top)] = temporary[index];
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
    int stack[MAX], top = -1;

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
            dequeue(stack, &top);
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
