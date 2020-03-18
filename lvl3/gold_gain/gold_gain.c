#include <stdlib.h>
#include <stdio.h>

void print_matrix(int **mtx, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%2d ", mtx[i][j]);
		printf("\n");
	}
}

int max2(int n1, int n2)
{
	return (n1 > n2 ? n1 : n2);
}

int max3(int n1, int n2, int n3)
{
	int max = 0;

	max = (n1 > n2 ? n1 : n2);
	max = (max > n3 ? max : n3);
	return max;
}

/*	Main idea
	from the rightmost colume, calculate the maximum possible value of
	of each tile backward.
	Store in another matrix which has the same size as real matrix.

					Start here
						V
	[ 1, 0, 0 ]	   [ 8, 4, 0 ]
	[ 0, 3, 4 ] => [ 7, 7, 4 ]
	[ 0, 0, 0 ]	   [ 7, 4, 0 ]
*/
int	gold_gain(int **mine, int n)
{
	// filled in treasure map
	int **tm = malloc(sizeof(int *) * n);
	for (int i = 0; i < n; i++)
	{
		tm[i] = malloc(sizeof(int) * n);
		for (int j = 0; j < n; j++)
			tm[i][j] = mine[i][j];
	}
	printf("before:\n");
	print_matrix(tm, n);

	// calculate max
	for (int j = n - 2; j >= 0; j--)
	{
		for (int i = 0; i < n; i++)	
		{
			if (i == 0)
				tm[i][j] += max2(tm[i][j + 1], tm[i + 1][j + 1]);
			else if (i == n - 1)
				tm[i][j] += max2(tm[i - 1][j + 1], tm[i][j + 1]);
			else
				tm[i][j] += max3(tm[i - 1][j + 1], tm[i][j + 1], tm[i + 1][j + 1]);
		}
	}
	printf("after:\n");
	print_matrix(tm, n);

	// find max value in first colume
	int max_gold = INT32_MIN;

	for (int i = 0; i < n; i++)
	{
		if (tm[i][0] > max_gold)
			max_gold = tm[i][0];
	}
	return (max_gold);
}

#include <time.h>

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int size = atoi(argv[1]);
		int rand_range = atoi(argv[2]);

		if (size <= 0 || rand_range <= 0)
		{
			printf("usage: ./a.out <size> <rand_range> must larger then 0");
			return 0;
		}
		
		srand(time(NULL));

		int **mine = malloc(sizeof(int *) * size);
		int i = -1;
		int j;
		while (++i < size)
		{
			j = -1;
			mine[i] = malloc(sizeof(int) * size);
			while (++j < size)
				mine[i][j] = rand() % 15;
		}
		printf("mine:\n");
		print_matrix(mine, size);
		printf("max: %d\n", gold_gain(mine, size));
	}
	else
		printf("usage: ./a.out <size> <rand_range>");
	return (0);
}