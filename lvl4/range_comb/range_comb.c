#include <stdlib.h>
#include <string.h>

#include <stdio.h>

void print_used(int n, int *used)
{
	for (int i = 0; i < n; i++)
		printf("%d", used[i]);
	printf("\n");
}

int is_all_used(int n, int *used)
{
	for (int i = 0; i < n; i++)
		if (used[i] == 0)
			return 0;
	return 1;
}

void permu(int n, int **arr, int *used, int *buf, int *cur_row, int cur_col)
{
	if (is_all_used(n, used))
		memcpy(arr[(*cur_row)++], buf, n * sizeof(int));
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (used[i] == 0)
			{
				used[i] = 1;
				buf[cur_col] = i;
				permu(n, arr, used, buf, cur_row, cur_col + 1);
				used[i] = 0;
			}
		}
	}
}

/* Main idea:
	Permutation: order matter and no repeat
	Combination: order doesn't matter and no repeat
	here we been asked permutation choose n from n

	In order for no repeatation, I'll use another array to track used number
	Store the permutation by recursion, copy own buffer to target array
*/
int    **range_comb(int n)
{
	int permu_num = 1;
	int **arr;
	int used[n], buf[n], cur_row = 0;

	// calculate permutation possible set, e.g. n = 3, P(3,3) = 3! fractrol
	for (int i = n; i > 0; i--)
		permu_num *= i;
	arr = malloc(sizeof(int *) * permu_num + 1);
	
	// Create mem space for result and used number tracking
	for (int i = 0; i < permu_num; i++)
	{
		arr[i] = malloc(sizeof(int) * n);
		used[i] = 0;
	}
	arr[permu_num] = 0;
	
	// permutation
	permu(n, arr, used, buf, &cur_row, 0);
	return arr;
}

// Test
// #include <stdio.h>

void	print_matrix(int n, int **mtx)
{
	int i = 0, j = 0;
	while (mtx[i] != 0)
	{
		for (j = 0; j < n; j++)
			printf("%d ", mtx[i][j]);
		printf("\n");
		i++;
	}
}

int main(void)
{
	int **arr1 = range_comb(3);
	print_matrix(3, arr1);
}