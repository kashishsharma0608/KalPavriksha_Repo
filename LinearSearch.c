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
int stringCompare(char *string1, char *string2)
{
    if (stringLength(string1) != stringLength(string2))
    {
        return 1;
    }
    int iterator = 0;
    while (string1[iterator] != '\0' && string2[iterator] != '\0')
    {
        if (string1[iterator] != string2[iterator])
        {
            return 1;
        }
        iterator++;
    }

    return 0;
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
coachAvailability *createNode(char *coachName, int availability)
{
    coachAvailability *newNode = (coachAvailability *)malloc(sizeof(coachAvailability));
    if (!newNode)
    {
        printf("Memory Alloaction failed");
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
        printf("No coach List found");
        return;
    }
    while (start != NULL)
    {
        printf("Coach name :%s ", start->coachName);
        printf("Availability :%d ", start->availability);
        printf("\n");
        start = start->next;
    }
}
void chechCoachAvailability(coachAvailability *start, char *coachNameToFind)
{
    int found = 0;
    if (start == NULL)
    {
        printf("No Coach Found");
        return;
    }
    while (start != NULL)
    {
        if ((stringCompare(start->coachName, coachNameToFind) == 0))
        {
            found = 1;
            if (start->availability == 0)
            {
                start->availability = 1;
                printf("Congratulation! You have been assigned %s for training.", start->coachName);
                return;
            }
        }
        start = start->next;
    }
    if (found == 0)
    {
        printf("sorry ! %s is not in our database.", coachNameToFind);
        return;
    }
    if (start == NULL)
    {
        printf("Sorry ! The coach asked is not available.");
    }
}
void checkAnyCoachAvailability(coachAvailability *start)
{
    if (start == NULL)
    {
        printf("No Coach Found");
        return;
    }
    while (start != NULL)
    {
        if (start->availability == 0)
        {
            start->availability = 1;
            printf("Congratulation! You have been assigned %s for training.", start->coachName);
            return;
        }
        start = start->next;
    }
    if (start == NULL)
    {
        printf("Sorry ! No coach is available.");
    }
}
void freeMemory(coachAvailability **start)
{
    coachAvailability *temp;
    while (*start != NULL)
    {
        temp = *start;
        free(temp);
        *start = (*start)->next;
    }
    *start = NULL;
}
int main()
{
    coachAvailability *head = NULL;
    int numberOfCoaches;
    printf("Enter the number of coaches in academy:");
    scanf("%d", &numberOfCoaches);
    if (numberOfCoaches <= 0)
    {
        printf("Sorry! no coach in the academy");
        return 0;
    }
    for (int iterator = 0; iterator < numberOfCoaches; iterator++)
    {
        char coachName[100];
        int availability;
        printf("Enter the name of the coach :");
        getchar();
        scanf("%[^\n]", coachName);
        getchar();
        printf("Enter the availability:");
        scanf("%d", &availability);
        createLinkedList(&head, coachName, availability);
    }
    do
    {
        printf("\nEnter \n 1. Check for the coach Availability by Name. \n 2. Display Coach List.\n 3. Check for any coach availability. \n 0. To exit the program\n Enter your choice:\n");
        int choice;
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("enter the name of the coach you want: ");
            getchar();
            char *coachNameToFind = (char *)malloc(100 * sizeof(char));
            scanf("%[^\n]", coachNameToFind);
            getchar();
            chechCoachAvailability(head, coachNameToFind);
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
            printf("Thank You!");
            return 0;
        }
        else
        {
            printf("please enter choice between 1 to 3 or 0 for exit.");
        }
    } while (1);
    freeMemory(&head);
    return 0;
}