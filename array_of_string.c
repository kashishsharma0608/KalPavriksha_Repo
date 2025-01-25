#include <stdio.h>
#include <stdlib.h>
int allocateMemory(int rows, int columns,char *names[rows][columns])
{
   
    for (int iterator = 0; iterator < rows; iterator++)
    {
        for (int iterator2 = 0; iterator2 < columns; iterator2++)
        {
            names[iterator][iterator2] = (char *)malloc(100 * sizeof(char));
            if (names[iterator][iterator2] == NULL)
            {
                printf("Memory allocation failed.\n");
                return 0;
            }
        }
    }
    return 1;
}
void inputNames(int rows, int columns,char *names[rows][columns])
{
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            printf("Enter name for row %d, column %d: ", row, column);
            scanf("%s", names[row][column]);
        }
    }
}
void printNames(int rows, int columns,char *names[rows][columns])
{
    printf("The Names are:\n");
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            printf("%s ", names[row][column]);
        }
        printf("\n");
    }
}
int isVowel(char character)
{
    return (character == 'A' || character == 'E' || character == 'I' || character == 'O' || character == 'U' ||
            character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u');
}
int countNamesStartingWithVowels(int rows, int columns,char *names[rows][columns])
{
    int count = 0;
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            if (isVowel(names[row][column][0]))
            {
                count++;
            }
        }
    }
    return count;
}
char *findLongestName(int rows, int columns,char *names[rows][columns])
{
    char *longestName = NULL;
    int maxLength = 0;
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            int length = 0;
            for (int stringIterator = 0; names[row][column][stringIterator] != '\0'; stringIterator++)
            {
                length++;
            }
            if (length > maxLength)
            {
                maxLength = length;
                longestName = names[row][column];
            }
        }
    }
    return longestName;
}

void freeMemory(int rows, int columns,char *names[rows][columns])
{
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            free(names[row][column]);
        }

    }
   
}
int main()
{
    int rows, columns;
    printf("Enter Rows and Columns: ");
    scanf("%d%d", &rows, &columns);
    if (rows <= 0 || columns <= 0)
    {
        printf("Invalid Input");
        return 0;
    }
    char *names[rows][columns];
    if(!allocateMemory(rows, columns,names)){
        return 0;
    }

    inputNames(rows, columns,names);
    printNames(rows, columns,names);

    int vowelStartCount = countNamesStartingWithVowels(rows, columns,names);
    printf("Number of names starting with vowels: %d\n", vowelStartCount);

    char *longestName = findLongestName(rows, columns,names);
    printf("Longest Name: %s\n", longestName);

    freeMemory(rows, columns,names);
    longestName=NULL;
    return 0;
}
