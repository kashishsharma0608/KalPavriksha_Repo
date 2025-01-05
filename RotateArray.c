#include <stdio.h>
#include <stdlib.h>
int main()
{
    int row;
    printf("enter row :");
    scanf("%d", &row);
    int *array[row];
    for (int iterator = 0; iterator < row; iterator++)
    {
        array[iterator] = (int *)malloc(row * sizeof(int));
    }
    printf("Enter elements in array:");
    for (int counter = 0; counter < row; counter++)
    {
        for (int inner_counter = 0; inner_counter < row; inner_counter++)
        {
            scanf("%d", &array[counter][inner_counter]);
        }
    }

    for (int counter = 0; counter < row; counter++)
    {

        for (int counter2 = counter + 1; counter2 < row; counter2++)
        {

            int temporary = array[counter][counter2];
            array[counter][counter2] = array[counter2][counter];
            array[counter2][counter] = temporary;
        }
    }

    for (int counter = 0; counter < row; counter++)
    {

        for (int counter2 = 0; counter2 < row / 2; counter2++)
        {

            int temporary = array[counter][counter2];
            array[counter][counter2] = array[counter][row - counter2 - 1];
            array[counter][row - counter2 - 1] = temporary;
        }
    }
    for (int counter = 0; counter < row; counter++)
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
