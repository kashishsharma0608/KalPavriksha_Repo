#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int rows, columns;
	printf(" Enter Rows and columns");
	scanf("%d%d", &rows, &columns);
	char ***strings = (char ***)malloc(rows * sizeof(char **));
	for (int index = 0; index < rows; index++)
	{
		strings[index] = (char **)malloc(columns * sizeof(char *));
		for (int index_col = 0; index_col < columns; index_col++)
		{
			strings[index][index_col] = (char *)malloc(100 * sizeof(char));
		}
	}
	printf("Enter the strings:\n");
	for (int row = 0; row < rows; row++)
	{
		for (int col = 0; col < columns; col++)
		{
			scanf("%s", strings[row][col]);
		}
	}
	char ch;
	printf("Enter a charater:");
	scanf(" %c", &ch);
	char *result=NULL;
	int max_occurence = 0;
	for (int r_index = 0; r_index < rows; r_index++)
	{

		for (int c_index = 0; c_index < columns; c_index++)
		{
			int count = 0;
			int length = strlen(strings[r_index][c_index]);
			for (int counter = 0; counter < length; counter++)
			{
				if (strings[r_index][c_index][counter] == ch)
				{
					count++;
				}
			}
			if (max_occurence < count)
			{
				max_occurence = count;
				result = strings[r_index][c_index];
			}
		}
	}
	if(result!=NULL) {
		printf("string with most occurrences :%s",result);
	}
	else {
		printf("no occurence found");
	}

	for(int index=0; index<rows; index++) {
		for(int index2=0; index2<columns; index2++) {
			free(strings[index][index2]);
		}
		free(strings[index]);
	}
	free(strings);
}
