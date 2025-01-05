#include <stdio.h>
#include <stdlib.h>
int main()
{
    int row, column;
    printf("enter row and column:");
    scanf("%d%d", &row, &column);
    int *array[row];
    for (int iterator = 0; iterator < row; iterator++)
    {
        array[iterator] = (int *)malloc(column * sizeof(int));
    }
    printf("Enter elements in array:");
    for (int counter = 0; counter < row; counter++)
    {
        for (int inner_counter = 0; inner_counter < column; inner_counter++)
        {
            scanf("%d", &array[counter][inner_counter]);
        }
    }

    for (int counter = 0; counter < row; counter++)
    {

        for (int counter2 = 0; counter2 < column; counter2++)
        {
            if (row == column)
            {
                int temporary = array[counter][counter2];
                array[counter][counter2] = array[counter2][counter];
                array[counter2][counter] = temporary;
            }
            else
            {
                printf("Square matrix require for rotation");
            }
        }
    }

    for (int counter = 0; counter < row; counter++)
    {

        for (int counter2 = 0; counter2 < column; counter2++)
        {

            int temporary = array[counter][column - 1 - counter2];
            array[counter][column - 1 - counter2] = array[counter2][column - 1 - counter2];
            array[counter2][column - 1 - counter2] = temporary;
        }
    }
    for (int counter = 0; counter < column; counter++)
    {

        for (int counter2 = 0; counter2 < row; counter2++)
        {
            printf("%d\t", array[counter][counter2]);
        }
        printf("\n");
    }

    for (int iterator = 0; iterator < row; iterator++)
    {
        free(array[iterator]);
    }
    return 0;
}