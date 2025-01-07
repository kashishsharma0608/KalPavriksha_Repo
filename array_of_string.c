#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int rows, columns;
    printf("Enter Rows and Columns:");
    scanf("%d%d", &rows, &columns);
    char ***names = (char ***)malloc(rows * sizeof(char **));
    for (int row = 0; row < rows; row++)
    {
        names[row] = (char **)malloc(columns * sizeof(char *));
        for (int cols = 0; cols < columns; cols++)
        {
            names[row][cols] = (char *)malloc(100 * sizeof(char));
        }
    }

    for (int row = 0; row < rows; row++)
    {
        for (int cols = 0; cols < columns; cols++)
        {
            printf("Enter name for row %d, column %d: ", row, cols);
            scanf("%s", names[row][cols]);
        }
    }
    printf("The Names are :\n");
    for (int row = 0; row < rows; row++)
    {
        for (int cols = 0; cols < columns; cols++)
        {
            printf("%s ", names[row][cols]);
        }
        printf("\n");
    }
    char *longest_name = (char *)malloc(100 * sizeof(char));
    int maxlength = 0;
    for (int index = 0; index < rows; index++)
    {
        for (int index2 = 0; index2 < columns; index2++)
        {
            if (strlen(names[index][index2]) > maxlength)
            {
                maxlength = strlen(names[index][index2]);
                longest_name = names[index][index2];
            }
        }
    }
    printf("Longest Name: ");
    printf("%s", longest_name);
    int vowel_start_count = 0;
    for (int index = 0; index < rows; index++)
    {
        for (int index2 = 0; index2 < columns; index2++)
        {
            char first_char = names[index][index2][0];
            if (first_char == 'A' || first_char == 'U' || first_char == 'O' || first_char == 'I' || first_char == 'E' || first_char == 'a' || first_char == 'u' || first_char == 'o' || first_char == 'i' || first_char == 'e')
            {
                vowel_start_count++;
            }
        }
    }
    printf("\nNumbers of name starting with Vowels:  ");
    printf("%d", vowel_start_count);
    for (int row = 0; row < rows; row++)
    {
        for (int cols = 0; cols < columns; cols++)
        {
            free(names[row][cols]);
        }
        free(names[row]);
    }
    free(names);

    return 0;
}
