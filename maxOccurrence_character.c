#include <stdio.h>
#include <stdlib.h>
int stringLength(const char *string)
{
    int length = 0;
    while (string[length] != '\0')
    {
        length++;
    }
    return length;
}
int countOccurrences(char *string, char character)
{
    int count = 0;
    for (int charIndex = 0; charIndex < stringLength(string); charIndex++)
    {
        if (string[charIndex] == character)
        {
            count++;
        }
    }
    return count;
}
char ***allocateMemory(int numberOfRows, int numberOfColumns)
{
    char ***stringMatrix = (char ***)malloc(numberOfRows * sizeof(char **));
    if (stringMatrix == NULL)
    {
        printf("Memory allocation failed for rows.\n");
        return NULL;
    }

    for (int rowIndex = 0; rowIndex < numberOfRows; rowIndex++)
    {
        stringMatrix[rowIndex] = (char **)malloc(numberOfColumns * sizeof(char *));
        if (stringMatrix[rowIndex] == NULL)
        {
            printf("Memory allocation failed for columns.\n");
            return NULL;
        }
        for (int columnIndex = 0; columnIndex < numberOfColumns; columnIndex++)
        {
            stringMatrix[rowIndex][columnIndex] = (char *)malloc(100 * sizeof(char));
            if (stringMatrix[rowIndex][columnIndex] == NULL)
            {
                printf("Memory allocation failed for string[%d][%d].\n", rowIndex, columnIndex);
                return NULL;
            }
        }
    }
    return stringMatrix;
}
void inputStrings(char ***stringMatrix, int numberOfRows, int numberOfColumns)
{
    printf("Enter the strings:\n");
    for (int rowIndex = 0; rowIndex < numberOfRows; rowIndex++)
    {
        for (int columnIndex = 0; columnIndex < numberOfColumns; columnIndex++)
        {
            scanf("%s", stringMatrix[rowIndex][columnIndex]);
        }
    }
}
char *findMaxOccurrenceString(char ***stringMatrix, int numberOfRows, int numberOfColumns, char character)
{
    char *resultString = NULL;
    int maxOccurrences = 0;

    for (int rowIndex = 0; rowIndex < numberOfRows; rowIndex++)
    {
        for (int columnIndex = 0; columnIndex < numberOfColumns; columnIndex++)
        {
            int occurrenceCount = countOccurrences(stringMatrix[rowIndex][columnIndex], character);
            if (occurrenceCount > maxOccurrences)
            {
                maxOccurrences = occurrenceCount;
                resultString = stringMatrix[rowIndex][columnIndex];
            }
        }
    }
    return resultString;
}
void freeMemory(char ***stringMatrix, int numberOfRows, int numberOfColumns)
{
    for (int rowIndex = 0; rowIndex < numberOfRows; rowIndex++)
    {
        for (int columnIndex = 0; columnIndex < numberOfColumns; columnIndex++)
        {
            free(stringMatrix[rowIndex][columnIndex]);
        }
        free(stringMatrix[rowIndex]);
    }
    free(stringMatrix);
}

int main()
{
    int numberOfRows, numberOfColumns;
    printf("Enter Number of Rows and Columns: ");
    if (scanf("%d%d", &numberOfRows, &numberOfColumns) != 2 || numberOfRows <= 0 || numberOfColumns <= 0)
    {
        printf("Invalid input. Rows and columns must be positive integers.\n");
        return 0;
    }
    char ***stringMatrix = allocateMemory(numberOfRows, numberOfColumns);
    if (stringMatrix == NULL)
    {
        return 0;
    }
    inputStrings(stringMatrix, numberOfRows, numberOfColumns);
    char character;
    printf("Enter a Character: ");
    scanf(" %c", &character);
    char *resultString = findMaxOccurrenceString(stringMatrix, numberOfRows, numberOfColumns, character);
    if (resultString != NULL)
    {
        printf("String with Most Occurrences: %s\n", resultString);
    }
    else
    {
        printf("No Occurrences Found.\n");
    }
    freeMemory(stringMatrix, numberOfRows, numberOfColumns);

    return 0;
}