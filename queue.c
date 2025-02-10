#include <stdio.h>
#include <stdlib.h>
typedef struct queue
{
	int data;
	struct queue *next;
} queue;
queue *createNode(int value)
{
	queue *newNode = (queue *)malloc(sizeof(queue));
	if (!newNode)
	{
		printf("Memory allocation failed.");
		return NULL;
	}
	newNode->data = value;
	newNode->next = NULL;
	return newNode;
}
int isEmpty(queue *front)
{
	if (front == NULL)
	{
		return 1;
	}
	return 0;
}
void enqueue(queue **front, queue **rear, int value)
{
	queue *newNode = createNode(value);
	if (!newNode)
	{
		printf("Queue cannot be created.\n");
		return;
	}
	if (isEmpty(*front))
	{
		*front = newNode;
		newNode->next = *front;
		*rear = newNode;
	}
	else
	{
		(*rear)->next = newNode;
		*rear = newNode;
		(*rear)->next = *front;
	}
}
void dequeue(queue **front, queue **rear)
{
	if (isEmpty(*front))
	{
		printf("Queue is empty\n");
		return;
	}

	queue *temporary = *front;
	if (*front == *rear)
	{
		*front = *rear = NULL;
	}
	else
	{
		*front = (*front)->next;
		(*rear)->next = *front;
	}
	printf("Dequeued element :%d", temporary->data);
	free(temporary);
}
void display(queue *front)
{
	if (isEmpty(front))
	{
		printf("List is empty\n");
		return;
	}
	queue *traverse = front;
	do
	{
		printf("%d ", traverse->data);
		traverse = traverse->next;
	} while (traverse != front);
	printf("\n");
}
int sizeOfQueue(queue *front)
{
	if (isEmpty(front))
	{
		return 0;
	}
	int counter = 0;
	queue *temporary = front;
	do
	{
		counter++;
		temporary = temporary->next;
	} while (temporary != front);
	return counter;
}
int peekOfQueue(queue *front)
{
	if (isEmpty(front))
	{
		return -1;
	}
	return front->data;
}
void freeQueue(queue **front, queue **rear)
{
	if (isEmpty(*front))
		return;
	queue *current = *front, *traverse;
	do
	{
		traverse = current;
		current = current->next;
		free(traverse);
	} while (current != *front);
	*front = *rear = NULL;
}
int main()
{
	queue *front = NULL, *rear = NULL;
	int numberOfOperation;
	printf("Enter the number of operations:\n");
	scanf("%d", &numberOfOperation);
	while(numberOfOperation<=0) {
		printf("Enter a non-negative number:\n");
		scanf("%d",&numberOfOperation);
	}
		for (int index = 0; index < numberOfOperation; index++)
		{
			int choice;
			printf("\n1.Enqueue\n2.Dequeue\n3.Peek of Queue\n4.Size of queue.\n5.Display\n0. Exit \nEnter your choice:");
			scanf("%d", &choice);
			if (choice == 1)
			{
				int value;
				scanf("%d", &value);
				enqueue(&front, &rear, value);
				printf("Value Added to queue: %d", value);
			}
			else if (choice == 2)
			{
				dequeue(&front, &rear);
			}
			else if (choice == 3)
			{
				printf("Peek of element is : %d ", peekOfQueue(front));
			}
			else if (choice == 4)
			{
				printf("Size of queue : %d", sizeOfQueue(front));
			}
			else if (choice == 5)
			{
				display(front);
			}
			else if (choice == 0)
			{
				printf("Thank you !");
				return 0;
			}
			else
			{
				printf("Choose between 1 to 4 or 0 to exit");
			}
		}
		freeQueue(&front, &rear);
		return 0;
	}
