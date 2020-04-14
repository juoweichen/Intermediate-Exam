#include <stdlib.h>
#include <string.h>

void odd_or_even(char c, int *odd, int *even, int sign)
{
	int num = c - 48;

	if (num % 2 == 0)
		(*even) += sign;
	else
		(*odd) += sign;
}

char *create_match(char *arr, int start, int clen)
{
	char *res = malloc(clen + 1);
	int i = 0;

	for (i = 0; i < clen; i++)
		res[i] = arr[start + i];
	res[i] = '\0';
	return res;
}

/*	Main idea:
	Starting from the max even number length of array(and always even),
	using window sliding technique to find if current subarray match the condition.
	if not found, shrink the search length and repeat
*/
char    *longest_subarray(char *arr)
{
	if (arr == 0)
		return 0;

	int len = strlen(arr);
	int clen = len % 2 == 0 ? len : len - 1;
	int odd = 0, even = 0;
	
	while (clen > 1)
	{
		odd = 0; 
		even = 0;

		// check first window
		for (int i = 0; i < clen; i++)
			odd_or_even(arr[i], &odd, &even, 1);
		if (odd == even)
			return create_match(arr, 0, clen);

		// Window Sliding
		for (int i = clen; i < len; i++)
		{
			// add rightmost one
			odd_or_even(arr[i], &odd, &even, 1);
			// substract leftmost one 
			odd_or_even(arr[i - clen], &odd, &even, -1);
			if (odd == even)
				return create_match(arr, i - clen + 1, clen);
		}
		clen -= 2;
	}
	return 0;
}

// Test
#include <stdio.h>

int main(void)
{
	char *arr1 = "134";
	printf("arr: %s, sub: %s\n", arr1, longest_subarray(arr1));

	char *arr2 = "1357913579024680213579";
	printf("arr: %s, sub: %s\n", arr2, longest_subarray(arr2));

	char *arr3 = "2010102";
	printf("arr: %s, sub: %s\n", arr3, longest_subarray(arr3));

}
