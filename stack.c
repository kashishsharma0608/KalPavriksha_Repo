#include <stdio.h>
#define MAX 100
int isEmpty(int front)
{
    return (front == -1);
}
void push(int queue1[], int queue2[], int *front1, int *rear1, int *front2, int *rear2, int value)
{
    if (isEmpty(*front1))
    {
        *front1 = *rear1 = 0;
        queue1[*rear1] = value;
        return;
    }
    *rear2 = -1;
    for (int index = *front1; index <= *rear1; index++)
    {
        queue2[++(*rear2)] = queue1[index];
    }
    *front1 = *rear1 = 0;
    queue1[*rear1] = value;
    for (int index = 0; index <= *rear2; index++)
    {
        queue1[++(*rear1)] = queue2[index];
    }
}
void pop(int queue1[], int *front, int *rear)
{
    if (isEmpty(*front))
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Popped Value is: %d\n", queue1[(*front)++]);
    if (*front > *rear)
    {
        *front = *rear = -1;
    }
}
void peek(int queue1[], int front)
{
    if (isEmpty(front))
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Peek is : %d", queue1[front]);
}
void size(int queue1[], int front, int rear)
{
    if (isEmpty(front))
    {
        printf("stack is empty\n");
        return;
    }
    printf("Size is :%d", (rear - front + 1));
}
int main()
{
    int queue1[MAX], queue2[MAX];
    int front1 = -1, rear1 = -1, front2 = -1, rear2 = -1;
    int numberOfOperations;
    printf("Enter the number of operations:");
    scanf("%d", &numberOfOperations);
    for (int index = 0; index < numberOfOperations; index++)
    {
        int choice;
        printf("1.Push\n2.Pop\n3.Peek\n4.Size\n0.Exit\nEnter choice:");
        scanf("%d", &choice);
        if (choice == 1)
        {
            int value;
            printf("\nEnter value:");
            scanf("%d", &value);
            push(queue1, queue2, &front1, &rear1, &front2, &rear2, value);
        }
        else if (choice == 2)
        {
            pop(queue1, &front1, &rear1);
        }
        else if (choice == 3)
        {
            peek(queue1, front1);
        }
        else if (choice == 4)
        {
            size(queue1, front1, rear1);
        }
        else if (choice == 0)
        {
            return 0;
        }
        else
        {
            printf("Enter between 1 to 5");
        }
    }
    return 0;
}
