#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct stack
{
	int data;
	struct stack *next;
} stack;
int isEmpty(stack *top)
{
	if (top == NULL)
	{
		return 1;
	}
	return 0;
}
stack *createNode(int value)
{
	stack *newNode = (stack *)malloc(sizeof(stack));
	if (!newNode)
	{
		printf("Allocation failed");
		return NULL;
	}
	newNode->data = value;
	newNode->next = NULL;
	return newNode;
}
stack *push(stack *top, int value)
{
	stack *newNode = createNode(value);
	if (isEmpty(top))
	{
		top = newNode;
	}
	else
	{
		newNode->next = top;
		top = newNode;
	}
	return top;
}
stack *pop(stack *top)
{
	if (isEmpty(top))
	{
		printf("List is empty");
		return NULL;
	}
	else
	{
		stack *traverse = top;
		top = top->next;
		printf("Element Popped:%d\n", traverse->data);
		free(traverse);
	}
	return top;
}
int peek(stack *top)
{
	if (isEmpty(top))
	{
		return -1;
	}
	return top->data;
}
int sizeOfStack(stack *top)
{
	if (isEmpty(top))
	{
		return -1;
	}
	int size = 0;
	while (top != NULL)
	{
		size++;
		top = top->next;
	}
	return size;
}
void display(stack *top)
{
	if (isEmpty(top))
	{
		printf("\n");
		return;
	}
	display(top->next);
	printf("%d ", top->data);
}
void freeStack(stack *top)
{
	while (top)
	{
		stack *temp = top;
		top = top->next;
		free(temp);
	}
}
int main()
{
	stack *top = NULL;
	int numberOfOperations = 0;
	printf("Enter the number of operations:");
	scanf("%d", &numberOfOperations);
	for (int index = 0; index < numberOfOperations; index++)
	{
		int choice;
		printf("\n1.Push onto stack\n2.Pop from stack\n3.Peek of stack\n4.Size of stack\n5.Display\n0.Exit\n Enter the choice:");
		scanf("%d", &choice);
		if (choice == 1)
		{
			int value;
			printf("Enter the Element: ");
			scanf("%d", &value);
			top = push(top, value);
		}
		else if (choice == 2)
		{
			top = pop(top);
		}
		else if (choice == 3)
		{
			int peekValue=peek(top);
			if(peekValue!=-1) {
			printf("Peek value is : %d",peekValue);
			}
			else {
				printf("Stack is empty");
			}
		}
		else if (choice == 4)
		{
			printf("\nStack size: %d", sizeOfStack(top));
		}
		else if (choice == 5)
		{
			if (isEmpty(top))
			{
				printf("list is empty");
			}
			else
			{
				printf("List: ");
				display(top);
			}
		}
		else if (choice == 0)
		{
			printf("Thank you!");
			return 0;
		}
		else
		{
			printf("Choose between 1 to 5 or 0 to exit");
		}
	}
	freeStack(top);
	return 0;
}
