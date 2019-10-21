#include <stdio.h>

struct s_node {
	int           value;
	struct s_node *right;
	struct s_node *left;
};

void	recur(struct s_node *cur, int leftmost, int rightmost)
{
	if (cur == NULL)
		return;

	if (leftmost && rightmost)
		printf("%d", cur->value);
	else if (leftmost || (cur->left == NULL && cur->right == NULL))
		printf(" %d", cur->value);

	recur(cur->left, leftmost, 0);
	recur(cur->right, 0, rightmost);

	if (rightmost && !leftmost && !(cur->left == NULL && cur->right == NULL))
		printf(" %d", cur->value);
}

void	perimeter(struct s_node *root)
{
	recur(root, 1, 1);
	printf("\n");
}