#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int calculateTraceOfMatrix(int *matrix[], int dimensions)
{
    int diagonalSum = 0;
    for (int index = 0; index < dimensions; index++)
    {
        diagonalSum += matrix[index][index];
    }
    return diagonalSum;
}
bool areTraceOfMatrixEqual(int sum1, int sum2)
{
    return sum1 == sum2;
}
int **allocateMatrix(int dimensions)
{
    int **matrix = (int **)malloc(dimensions * sizeof(int *));
    if (matrix == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    for (int iterator = 0; iterator < dimensions; iterator++)
    {
        matrix[iterator] = (int *)malloc(dimensions * sizeof(int));
        if (matrix[iterator] == NULL)
        {
            printf("Memory allocation failed!\n");
            return NULL;
        }
    }
    return matrix;
}

void freeMatrix(int *matrix[], int dimensions)
{
    for (int i = 0; i < dimensions; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

void inputMatrixElements(int *matrix[], int dimensions)
{
    for (int row = 0; row < dimensions; row++)
    {
        for (int column = 0; column < dimensions; column++)
        {
            scanf("%d", &matrix[row][column]);
        }
    }
}

int main()
{
    int dimensions;
    printf("Enter the dimension of the square matrix: ");
    scanf("%d", &dimensions);

    if (dimensions <= 0)
    {
        printf("Invalid matrix dimension. The dimension must be greater than 0.\n");
        return 0;
    }

    int **matrix1 = allocateMatrix(dimensions);
    int **matrix2 = allocateMatrix(dimensions);
    printf("Enter the elements in Matrix1\n");
    inputMatrixElements(matrix1, dimensions);
    printf("Enter the elements in Matrix2\n");
    inputMatrixElements(matrix2, dimensions);
    int matrix1DiagonalSum = calculateTraceOfMatrix(matrix1, dimensions);
    int matrix2DiagonalSum = calculateTraceOfMatrix(matrix2, dimensions);
    if (areTraceOfMatrixEqual(matrix1DiagonalSum, matrix2DiagonalSum))
    {
        printf("The matrices are traces of each other.\n");
    }
    else
    {
        printf("The matrices are not traces of each other.\n");
    }
    freeMatrix(matrix1, dimensions);
    freeMatrix(matrix2, dimensions);
    return 0;
}