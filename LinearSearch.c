#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct coachAvailability
{
    char coachName[100];
    int availability;
    struct coachAvailability *next;
} coachAvailability;

int stringLength(char *string)
{
    int length = 0;
    while (string[length] != '\0')
    {
        length++;
    }
    return length;
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

char toLower(char character)
{
    if (character >= 'A' && character <= 'Z')
    {
        return character + ('a' - 'A');
    }
    return character;
}

int stringCaseCompare(char *string1, char *string2)
{
    while (*string1 != '\0' || *string2 != '\0')
    {
        char c1 = toLower(*string1);
        char c2 = toLower(*string2);

        if (c1 != c2)
        {
            return (c1 - c2);
        }

        string1++;
        string2++;
    }
    return 0;
}

coachAvailability *createNode(char *coachName, int availability)
{
    coachAvailability *newNode = (coachAvailability *)malloc(sizeof(coachAvailability));
    if (!newNode)
    {
        printf("Memory Allocation failed");
        return NULL;
    }
    stringCopy(newNode->coachName, coachName);
    newNode->availability = availability;
    newNode->next = NULL;
    return newNode;
}

void createLinkedList(coachAvailability **start, char *coachName, int availability)
{
    coachAvailability *newNode = createNode(coachName, availability);
    if (newNode == NULL)
    {
        return;
    }
    if (*start == NULL)
    {
        *start = newNode;
    }
    else
    {
        coachAvailability *pointer = *start;
        while (pointer->next != NULL)
        {
            pointer = pointer->next;
        }
        pointer->next = newNode;
    }
}

void displayCoachList(coachAvailability *start)
{
    if (start == NULL)
    {
        printf("No coach List found\n");
        return;
    }
    while (start != NULL)
    {
        printf("Coach name: %s | Availability: %d\n", start->coachName, start->availability);
        start = start->next;
    }
}

void checkCoachAvailability(coachAvailability *start, char *coachNameToFind)
{
    int found = 0;
    if (start == NULL)
    {
        printf("No Coach Found\n");
        return;
    }
    while (start != NULL)
    {
        if (stringCaseCompare(start->coachName, coachNameToFind) == 0)
        {
            found = 1;
            if (start->availability == 0)
            {
                start->availability = 1;
                printf("Congratulations! You have been assigned %s for training.\n", start->coachName);
                return;
            }
        }
        start = start->next;
    }
    if (found == 0)
    {
        printf("Sorry! %s is not in our database.\n", coachNameToFind);
    }
    else
    {
        printf("Sorry! The coach asked is not available.\n");
    }
}

void checkAnyCoachAvailability(coachAvailability *start)
{
    if (start == NULL)
    {
        printf("No Coach Found\n");
        return;
    }
    while (start != NULL)
    {
        if (start->availability == 0)
        {
            start->availability = 1;
            printf("Congratulations! You have been assigned %s for training.\n", start->coachName);
            return;
        }
        start = start->next;
    }
    printf("Sorry! No coach is available.\n");
}

void freeMemory(coachAvailability **start)
{
    coachAvailability *temp;
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
    coachAvailability *head = NULL;
    int numberOfCoaches;

    printf("Enter the number of coaches in the academy:\n");
    scanf("%d", &numberOfCoaches);
    if (numberOfCoaches < 0)
    {
        printf("Enter non-negative number:\n");
        scanf("%d", &numberOfCoaches);
    }
    if (numberOfCoaches == 0)
    {
        printf("Sorry! No coach in the academy.\n");
        return 0;
    }

    for (int i = 0; i < numberOfCoaches; i++)
    {
        char coachName[100];
        int availability;
        printf("Enter the name of the coach: ");
        getchar();
        scanf(" %[^\n]", coachName);
        printf("Enter the availability (0 for available, 1 for unavailable):");
        scanf("%d", &availability);
        createLinkedList(&head, coachName, availability);
    }

    while (1)
    {
        printf("\nEnter:\n 1. Check for the coach availability by name\n 2. Display Coach List\n 3. Check for any coach availability\n 0. To exit the program\nEnter your choice: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter the name of the coach you want: ");
            getchar();
            char coachNameToFind[100];
            scanf("%[^\n]", coachNameToFind);
            checkCoachAvailability(head, coachNameToFind);
        }
        else if (choice == 2)
        {
            printf("The Coach List:\n");
            displayCoachList(head);
        }
        else if (choice == 3)
        {
            checkAnyCoachAvailability(head);
        }
        else if (choice == 0)
        {
            printf("Thank You!\n");
            break;
        }
        else
        {
            printf("Please enter a choice between 1 to 3 or 0 for exit.\n");
        }
    }
    freeMemory(&head);
    return 0;
}
