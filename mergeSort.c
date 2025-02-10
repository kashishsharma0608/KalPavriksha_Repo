#include <stdio.h>
#include <stdlib.h>

typedef struct library
{
	char title[100];
	struct library *next;
} library;

int stringLength(char *string)
{
	int length = 0;
	while (string[length] != '\0')
	{
		length++;
	}
	return length;
}

int stringCompare(char *string1, char *string2)
{
	int index = 0;
	while (string1[index] != '\0' && string2[index] != '\0')
	{
		if (string1[index] < string2[index])
			return -1;
		if (string1[index] > string2[index])
			return 1;
		index++;
	}
	return string1[index] - string2[index];
}

void stringCopy(char destination[], char source[])
{
	int index = 0;
	while (source[index] != '\0')
	{
		destination[index] = source[index];
		index++;
	}
	destination[index] = '\0';
}

library *createNode(char *bookTitle)
{
	library *newBook = (library *)malloc(sizeof(library));
	if (!newBook)
	{
		printf("Allocation failed!");
		return NULL;
	}
	stringCopy(newBook->title, bookTitle);
	newBook->next = NULL;
	return newBook;
}

void createLinkedList(library **head, char *bookTitle)
{
	library *newBook = createNode(bookTitle);
	if (*head == NULL)
	{
		*head = newBook;
	}
	else
	{
		library *currentBook = *head;
		while (currentBook->next != NULL)
		{
			currentBook = currentBook->next;
		}
		currentBook->next = newBook;
	}
}

void display(library *head)
{
	if (head == NULL)
	{
		printf("List is empty");
		return;
	}
	while (head != NULL)
	{
		printf("%s\n", head->title);
		head = head->next;
	}
	printf("\n");
}

void freeMemory(library **head)
{
	library *tempBook;
	while (*head != NULL)
	{
		tempBook = *head;
		*head = (*head)->next;
		free(tempBook);
	}
	*head = NULL;
}

void splitList(library *head, library **firstHalf, library **secondHalf)
{
	library *slow = head, *fast = head->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*firstHalf = head;
	*secondHalf = slow->next;
	slow->next = NULL;
}

library *mergeSortedList(library *firstHalf, library *secondHalf)
{
	if (firstHalf == NULL)
		return secondHalf;
	if (secondHalf == NULL)
		return firstHalf;

	library *mergedList = NULL;
	if (stringCompare(firstHalf->title, secondHalf->title) <= 0)
	{
		mergedList = firstHalf;
		mergedList->next = mergeSortedList(firstHalf->next, secondHalf);
	}
	else
	{
		mergedList = secondHalf;
		mergedList->next = mergeSortedList(firstHalf, secondHalf->next);
	}
	return mergedList;
}

void mergeSort(library **head)
{
	library *currentHead = *head;
	if (currentHead == NULL || currentHead->next == NULL)
	{
		return;
	}

	library *firstHalf, *secondHalf;
	splitList(currentHead, &firstHalf, &secondHalf);
	mergeSort(&firstHalf);
	mergeSort(&secondHalf);
	*head = mergeSortedList(firstHalf, secondHalf);
}

int main()
{
	library *head = NULL;
	int numberOfBooks;

	printf("Enter the number of books: ");
	scanf("%d", &numberOfBooks);

	if (numberOfBooks <= 0)
	{
		printf("Invalid Input");
		return 0;
	}

	for (int i = 0; i < numberOfBooks; i++)
	{
		char *bookTitle = (char *)malloc(100 * sizeof(char));
		if (bookTitle == NULL)
		{
			printf("Memory allocation failed\n");
			return 0;
		}
		printf("Enter book title:\n");
		scanf(" %[^\n]", bookTitle);
		createLinkedList(&head, bookTitle);
		free(bookTitle);
	}

	if (numberOfBooks == 1)
	{
	    printf("List :");
		display(head);
		freeMemory(&head);
		return 0;
	}
    printf("List before sorting:\n");
	display(head);
	mergeSort(&head);
	printf("List After sorting:\n");
	display(head);
	freeMemory(&head);
	return 0;
}
