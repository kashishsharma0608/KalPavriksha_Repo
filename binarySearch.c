#include <stdio.h>
#include <stdlib.h>
typedef struct painterProblem
{
	int boardLength;
	struct painterProblem *next;
} painterProblem;
painterProblem *createNode(int value)
{
	painterProblem *newNode = (painterProblem *)malloc(sizeof(painterProblem));
	if (!newNode)
	{
		printf("memory allocation failed");
		return 0;
	}
	newNode->boardLength = value;
	newNode->next = NULL;
	return newNode;
}
void createBoardList(painterProblem **start, int value)
{
	painterProblem *newNode = createNode(value);
	if (*start == NULL)
	{
		*start = newNode;
	}
	else
	{
		painterProblem *pointer = *start;
		while (pointer->next != NULL)
		{
			pointer = pointer->next;
		}
		pointer->next = newNode;
	}
}
void display(painterProblem *start)
{
	if (start == NULL)
	{
		printf("List is empty");
		return;
	}
	while (start != NULL)
	{
		printf("%d ", start->boardLength);
		start = start->next;
	}
}
int getMaxElement(painterProblem *start)
{
	int maximum = 0;
	while (start != NULL)
	{
		if (start->boardLength > maximum)
		{
			maximum = start->boardLength;
		}
		start = start->next;
	}
	return maximum;
}
int getSum(painterProblem *start)
{
	int sum = 0;
	while (start != NULL)
	{
		sum += start->boardLength;
		start = start->next;
	}
	return sum;
}
int numberOfPainters(painterProblem *start, int maximum)
{
	int totalSum = 0, numberOfPaintersCount = 1;
	while (start != NULL)
	{
		totalSum += start->boardLength;
		if (totalSum > maximum)
		{
			totalSum = start->boardLength;
			numberOfPaintersCount++;
		}
		start = start->next;
	}
	return numberOfPaintersCount;
}
int minimumTimeToPaint(painterProblem *start, int numberOfPaintersGiven)
{
	int beginning = getMaxElement(start);
	int ending = getSum(start);
	while (beginning <= ending)
	{
		int middle = beginning + (ending - beginning) / 2;
		int requiredPainters = numberOfPainters(start, middle);
		if (requiredPainters <= numberOfPaintersGiven)
		{
			ending = middle - 1;
		}
		else
		{
			beginning = middle + 1;
		}
	}
	return beginning;
}
void freeMemory(painterProblem **start)
{
	painterProblem *temp;
	while (*start != NULL)
	{
		temp = *start;
		*start = (*start)->next;
		free(temp);
	}
	*start = NULL;
}
int main()
{
	painterProblem *start = NULL;
	int numberofBoards;
	printf("Enter the number of boards: ");
	scanf("%d", &numberofBoards);
	if (numberofBoards <= 0)
	{
		printf("Enter a positive integer:");
		return 0;
	}
	for (int iterator = 0; iterator < numberofBoards; iterator++)
	{
		int boardLength;
		scanf("%d", &boardLength);
		while(boardLength<=0) {
			printf("Enter a non-negative values for boards:\n");
			scanf("%d",&boardLength);
		}
		createBoardList(&start, boardLength);
	}
	printf("Enter the number of painters: ");
	int numberOfPaintersGiven;
	scanf("%d", &numberOfPaintersGiven);
	printf("Minimum time to paint: ");
	int result = minimumTimeToPaint(start, numberOfPaintersGiven);
	printf("%d", result);
	freeMemory(&start);
	return 0;
}
