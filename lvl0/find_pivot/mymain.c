#include <stdio.h>

int find_pivot(int *arr, int n);

int main()
{
	int arr1[6] = {1, 2, 3, 4, 0, 6};
	int n1 = 6;

	printf("%d\n", find_pivot(arr1, n1));

	int arr2[4] = {-5, 10, 2, 5};
	int n2 = 4;

	printf("%d\n", find_pivot(arr2, n2));

	int arr3[5] = {1, 100, 0, 0, 1};
	int n3 = 5;

	printf("%d\n", find_pivot(arr3, n3));

	int arr4[3] = {7, 9, 8};
	int n4 = 3;

	printf("%d\n", find_pivot(arr4, n4));

	int arr5[2] = {1, 2};
	int n5 = 2;

	printf("%d\n", find_pivot(arr5, n5));
	return (0);
}
