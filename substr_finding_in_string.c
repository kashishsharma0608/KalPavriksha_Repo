#include <stdio.h>
#include <stdlib.h>
int length_of_string(char *string)
{
    int count = 0, index = 0;
    while (string[index] != '\0')
    {
        count++;
        index++;
    }
    return count;
}
int main()
{
    int rows, columns;
    printf("Enter Row and Column:");
    scanf("%d%d", &rows, &columns);
    char *strings[rows][columns];
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            strings[row][column] = (char *)malloc(100 * sizeof(char));
        }
    }
    printf("Enter String:\n");
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            scanf("%s", strings[row][column]);
        }
    }
    printf("Entered String:\n");
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            printf("%s ", strings[row][column]);
        }
        printf("\n");
    }
    char *substr = (char *)malloc(100 * sizeof(char));
    printf("Enter the substring to check:");
    scanf("%s", substr);
    printf("Entered sub-string is : %s", substr);
    int substr_length = length_of_string(substr);
    int match_count = 0, match_flag = 0;
    printf("\nThe matched string of substr '%s' is :", substr);
    for (int row_index = 0; row_index < rows; row_index++)
    {
        for (int column_index = 0; column_index < columns; column_index++)
        {
              match_flag = 0;
            int str_len = length_of_string(strings[row_index][column_index]);
            for (int char_index = 0; char_index < str_len; char_index++)
            {
              
                int index = 0, match_flag_counter = 0;

               
                    while (index < substr_length  && substr[index] == strings[row_index][column_index][char_index + index])
                    {
                        index++;
                        match_flag_counter++;
                    }
                
                if (match_flag_counter == substr_length)
                {
                    match_flag = 1;
                    break;
                }
            }

            if (match_flag)
            {
                printf("%s\n", strings[row_index][column_index]);
                match_count++;
            }
        }
        printf("\n");
    }
    printf("Matched count: %d ", match_count);
    return 0;
}
