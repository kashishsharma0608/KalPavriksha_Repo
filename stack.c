#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

typedef struct
{
    int stack_array[MAX_LENGTH];
    int top;
} stacks;

void initialize_stack(stacks *stack)
{
    stack->top = -1;
}

int is_empty(stacks *stack)
{
    return stack->top == -1;
}

int is_full(stacks *stack)
{
    return stack->top == MAX_LENGTH - 1;
}

void push_stack(stacks *stack, int value)
{
    if (is_full(stack))
    {
        printf("Overflow! Stack is full\n");
        return;
    }
    stack->stack_array[++stack->top] = value;
    printf("Pushed Value is: %d\n", value);
}

int pop_stack(stacks *stack)
{
    if (is_empty(stack))
    {
        printf("Underflow! Stack is empty\n");
        return -1;
    }
    return stack->stack_array[stack->top--];
}

int peek_of_stack(stacks *stack)
{
    if (is_empty(stack))
    {
        printf("Underflow! Stack is empty\n");
        return -1;
    }
    return stack->stack_array[stack->top];
}

int size_of_stack(stacks *stack)
{
    return stack->top + 1;
}
void display(stacks *stack)
{
    if (is_empty(stack))
    {
        printf("Stack is empty");
        return;
    }
    printf("Element of stack are :");
    for (int index = 0; index <= stack->top; index++)
    {
        printf("%d ", stack->stack_array[index]);
    }
    printf("\n");
}
int main()
{
    stacks stack_instance;
    stacks *stack = &stack_instance;
    initialize_stack(stack);
    int number_of_operations;
    printf("Enter number of operation to input: ");
    scanf("%d", &number_of_operations);
    for (int index = 0; index < number_of_operations; index++)
    {
        int choice;
        printf("\n1. Push onto stack\n2. Pop from stack\n3. Peek of stack\n4.size of stack\n5.Display Stack\n0. Exit");
        scanf("%d", &choice);
        if (choice == 1)
        {
            int value;
            printf("Enter the value to be inserted:");
            scanf("%d", &value);
            push_stack(stack, value);
        }
        else if (choice == 2)
        {
            printf("Element popped: %d\n", pop_stack(stack));
        }
        else if (choice == 3)
        {
            printf("Element at peek: %d\n", peek_of_stack(stack));
        }
        else if (choice == 4)
        {
            printf("Size of stack: %d\n", size_of_stack(stack));
        }
        else if (choice == 5)
        {
            display(stack);
        }
        else if (choice == 0)
        {
            printf("Thank you !");
            return 0;
        }
        else
        {
            printf("Invalid choice ! chosse between 1 to 5");
        }
    }
    return 0;
}
