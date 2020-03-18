#include <stdio.h>

struct s_node
{
	int value;
	struct s_node *right;
	struct s_node *left;
};

void recur(struct s_node *cur, int leftmost, int rightmost)
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

/* main idea: 
	Need to know what current state is at leftmost/middle/rightmost
	indicator == (leftmost, rightmost)
	(1, 1) == top node
	(1, 0) == leftmost
	(0, 1) == rightmost
	(0, 0) == middle

					  92 (1, 1)
	                 / \
	                /   \
	        (1, 0) 85   26 (0, 1) 
	              /       \
	      (1, 0) 79       64 (0, 1) 
	              \       / \
	       (0, 0) 10     /   \
	              /     /     \
	      (0, 0) 39    /       \
	            /     /         \
	           35    /           \
	          /     /             \
	         96    /               \
	              /                 \
	      (0, 0) 40                 78 (0, 1) 
	            / \                 / \
	           /   \               /   \
	          /     \      (0, 0) 2    85 (0, 1) 
	         /       \           / \     \
	        /         \         /   \    51 (0, 1) 
	       /           \       /     \
	      /             \     33     11
	     88             10     \     /
	    / \             / \    55   99 (0, 0) 
	   /   \           /   \
	  12   55         52   87
	 /     / \       / \     \
	58    /   \     /   \    31
	     58   41   22   35
*/
void perimeter(struct s_node *root)
{
	recur(root, 1, 1);
	printf("\n");
}

// Test
#define NODE(value, left, right) &(struct s_node){value, right, left}

int main(void)
{
	struct s_node *root1 = NODE(
		92,
		NODE(
			85,
			NODE(
				79,
				0,
				NODE(
					10,
					NODE(
						39,
						NODE(
							35,
							NODE(96, 0, 0),
							0),
						0),
					0)),
			0),
		NODE(
			26,
			0,
			NODE(
				64,
				NODE(
					40,
					NODE(
						88,
						NODE(
							12,
							NODE(58, 0, 0),
							0),
						NODE(
							55,
							NODE(58, 0, 0),
							NODE(41, 0, 0))),
					NODE(
						10,
						NODE(
							52,
							NODE(22, 0, 0),
							NODE(35, 0, 0)),
						NODE(
							87,
							0,
							NODE(31, 0, 0)))),
				NODE(
					78,
					NODE(
						2,
						NODE(
							33,
							0,
							NODE(55, 0, 0)),
						NODE(
							11,
							NODE(99, 0, 0),
							0)),
					NODE(
						85,
						0,
						NODE(51, 0, 0))))));
	perimeter(root1);

	// struct s_node *root2 = NODE(12, 0, 0);

	// perimeter(root2);
}