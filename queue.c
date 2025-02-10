#include <stdio.h>

#define MAX 100
int isEmpty(int front)
{
	return (front == -1);
}
void enqueue(int capacity, int queue[], int *front, int *rear, int value)
{

	if ((*rear + 1) % capacity == *front)
	{
		printf("Queue is full\n");
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
void dequeue(int capacity, int queue[], int *front, int *rear)
{
	if (*front == -1)
	{
		printf("Queue is empty!");
	}
	else if (*front == *rear)
	{
		*front = -1;
		*rear = -1;
	}
	else
	{
		printf("Dequeue element: %d ", queue[*front]);
		*front = (*front + 1) % capacity;
	}
}
int peekOfQueue(int front, int queue[])
{
	if (isEmpty(front))
	{
		return -1;
	}
	return queue[front];
}
int sizeOfQueue(int front, int rear, int capacity) {
	if (isEmpty(front)) return 0;
	return (rear >= front) ? (rear - front + 1) : (capacity - front + rear + 1);
}
void display(int queue[], int front, int rear, int capacity)
{
	if (front == -1)
	{
		printf("Queue is empty\n");
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
	printf("enter capacity:");
	scanf("%d", &capacity);

	int numberOfOperations;
	printf("Enter the number of operations:");
	scanf("%d", &numberOfOperations);

	for (int index = 0; index < numberOfOperations; index++)
	{
		int choice;
		printf("\n 1. Enqueue \n 2. Dequeue \n 3. Peek \n 4. Size \n 5. Display \n 0. Exit\n Enter choice: ");
		scanf("%d", &choice);

		if (choice == 1)
		{
			int value;
			printf("Enter the element to insert:");
			scanf("%d", &value);
			enqueue(capacity, queue, &front, &rear, value);
		}
		else if (choice == 2)
		{
			dequeue(capacity, queue, &front, &rear);
		}
		else if (choice == 3)
		{
			int peekValue = peekOfQueue(front, queue);
			if (peekValue == -1)
				printf("Queue is empty\n");
			else
				printf("Peek element: %d\n", peekValue);
		}
		else if (choice == 4)
		{
			printf("Size of queue: %d", sizeOfQueue(front, rear,capacity));
		}
		else if (choice == 5)
		{
			display(queue, front, rear, capacity);
		}
		else if (choice == 0)
		{
			printf("Thank you !");
			return 0;
		}
		else
		{
			printf("Enter the choice between 1 to 5 or 0 for exit");
		}
	}

	return 0;
}
