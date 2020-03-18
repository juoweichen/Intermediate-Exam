struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int recur(struct s_node *cur, int *width)
{
	int lw, rw;

	if (cur == 0)
		return 0;
	lw = recur(cur->left, width);
	rw = recur(cur->right, width);
	if (lw + rw + 1 > *width)
		*width = lw + rw + 1;
	return (lw > rw ? lw + 1 : rw + 1);
}

/*	Main idea
	need to keep record the widthest
	is current width larger the widthest?
	if yes, replace width
	if no, return longest under current node
*/
int	width_tree(struct s_node *n)
{
	int width = 0;

	recur(n, &width);
	return width;
}

// Test
#include <stdio.h>

#define NODE(value, left, right) &(struct s_node){value, right, left}

int main()
{
	struct s_node *root1 = NODE(
		1,	// 0
		NODE(
			2,	// 1
			NODE(
				3,	// 2 
				0, 
				0 
			),
			NODE(
				4,	// 2
				NODE(
					6,	// 3
					0, 
					0
				),
				0
			)
		),
		NODE(
			5,	// 1
			NODE(
				7,	// 2
				0,
				0
			),
			NODE(
				8,	// 2
				0,
				0
			)
		)
	);
	printf("r1: %d\n", width_tree(root1));

	struct s_node *root2 = NODE(
		1,
		NODE(
			2,
			NODE(
				4,
				NODE(
					5,
					NODE(8, 0, 0),
					0
					),
				NODE(6, 0, 0)
				),
			NODE(7,
				NODE(
					9,
					NODE(11, 0, 0),
					NODE(12, 0, 0)
					),
				NODE(
					10,
					0,
					NODE(13, 0, 0)
					)
				)
			),
		NODE(3, 0, 0)
	);
	printf("r2: %d\n", width_tree(root2));

	struct s_node *root3 = NODE(1, 0, 0);
	printf("r3: %d\n", width_tree(root3));
}