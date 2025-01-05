#include <stdio.h>
#include <stdlib.h>
int main()
{
    int row;
    printf("enter the number of rows:");
    scanf("%d", &row);
    int column;
    printf("enter the number of columns:");
    scanf("%d", &column);
    int *array[row];
    int counter = 0;
    for (int iterator = 0; iterator < row; iterator++)
    {
        array[iterator] = (int *)malloc(column * sizeof(int));
    }
    for (int iterator = 0; iterator < row; iterator++)
    {
        for (int innear_iterator = 0; innear_iterator < column; innear_iterator++)
        {
            scanf("%d", &array[iterator][innear_iterator]);
        }
    }
    int *temporary_array = (int *)malloc(100 * sizeof(int));
    int index = 0;
    int left = 0, right = column - 1, top = 0, bottom = row - 1;
    while (left <= right && top <= bottom)
    {
        for (counter = left; counter <= right; counter++)
        {
            temporary_array[index++] = array[top][counter];
        }

        top++;

        for (counter = top; counter <= bottom; counter++)
        {
            temporary_array[index++] = array[counter][right];
        }
        right--;
        if (top <= bottom)
        {
            for (counter = right; counter >= left; counter--)
            {
                temporary_array[index++] = array[bottom][counter];
            }
            bottom--;
        }

        if (left <= right)
        {
            for (counter = bottom; counter >= top; counter--)
            {
                temporary_array[index++] = array[counter][left];
            }
            left++;
        }
    }
    int temp_index = 0;
    for (int outer_counter = 0; outer_counter < row; outer_counter++)
    {
        for (int inner_counter = 0; inner_counter < column; inner_counter++)
        {
            if (temp_index < row * column)
            {
                array[outer_counter][inner_counter] = temporary_array[temp_index++];
            }
        }
    }
    for (int iterator = 0; iterator < row; iterator++)
    {

        for (int innear_iterator = 0; innear_iterator < column; innear_iterator++)
        {
            printf("%d\t", array[iterator][innear_iterator]);
        }

        printf("\n");
    }
}