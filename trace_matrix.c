#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int diagonal_Sum(int *matrix[], int dimensions)
{
    int matrix_sum = 0;
    for (int index = 0; index < dimensions; index++)
    {
        matrix_sum += matrix[index][index];
    }
    return matrix_sum;
}
bool check_trace(int sum1, int sum2)
{
    return sum1 == sum2;
}
int main()
{
    int dimensions;
    printf("Enter the dimension of the square matrix:");
    scanf("%d", &dimensions);
    int *matrix1[dimensions];
    int *matrix2[dimensions];
    for (int index = 0; index < dimensions; index++)
    {
        matrix1[index] = (int *)malloc(dimensions * sizeof(int));
        matrix2[index] = (int *)malloc(dimensions * sizeof(int));
    }
    printf("Enter the elements in matrix 1:");
    for (int index = 0; index < dimensions; index++)
    {
        for (int index_col = 0; index_col < dimensions; index_col++)
        {
            scanf("%d", &matrix1[index][index_col]);
        }
    }
    printf("Enter the elements in matrix 2:");
    for (int index = 0; index < dimensions; index++)
    {
        for (int index_col = 0; index_col < dimensions; index_col++)
        {
            scanf("%d", &matrix2[index][index_col]);
        }
    }
    int matrix1_sum = diagonal_Sum(matrix1, dimensions);
    int matrix2_sum = diagonal_Sum(matrix2, dimensions);
    int result = check_trace(matrix1_sum, matrix2_sum);
    if (result)
    {
        printf("The matrix are traces of each other");
    }
    else
    {
        printf("The Matrix are not trace of each other");
    }

    return 0;
}
