struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int get_tree_size(struct s_node *n, int half_size, int *find_spit)
{
	int size = 0;

	if (n == 0)
		return (0);
	size = 1 + get_tree_size(n->left, half_size, find_spit) + \
		get_tree_size(n->right, half_size, find_spit);
	if (size == half_size)
		*find_spit = 1;
	return size;
}

/*	Main idea
	1. get the total size
	2. Travel through tree again, calculating subtree size, 
		if the sub-size == total / 2, means it can split
*/
int	can_split(struct s_node *n)
{
	int find_split = 0;
	int total = get_tree_size(n, 0, &find_split);
	get_tree_size(n, total / 2, &find_split);
	return (find_split);
}

// test ---------------------------------------------------------------
#include <stdio.h>
#define NODE(value, left, right) &(struct s_node){value, left, right}

int main()
{
/*
	       28
	       /
	      51
	     / \
	    /   \
	   26   48
	  / \
	 /   \
	76   13
*/
	struct s_node *root0 = NODE(
		28,
		NODE(
			51,
			NODE(
				26,
				NODE(76,0,0),
				NODE(13,0,0)
			),
			NODE(48, 0, 0)
		),
		0
	);
	printf("Should be 1: %d\n", can_split(root0));

/*
           10
           / \
          11  9
         / \   \
        /   \   \
       6     9   8
      / \         \
     /   \         \
    7   13          7
   /                 
  /                   
 8                     
*/
	struct s_node *root1 = NODE(
		10,
		NODE(
			11,
			NODE(
				6,
				NODE(7, 
					NODE(8, NULL, NULL),
					NULL
					),
				NODE(13, NULL, NULL)
				),
			NODE(9, NULL, NULL)
			),
		NODE(
			9,
			NODE(
				8,
				NODE(
					7,
					0, //NODE(6, NULL, NULL),
					0
					),
				NULL
				),
			NULL)
		);
	printf("Should be 0: %d\n", can_split(root1));

	struct s_node *root2 = NODE(1, 0, 0);
	printf("Should be 0: %d\n", can_split(root2));

	struct s_node *root3 = NODE(1, NODE(2, 0, 0), 0);
	printf("Should be 1: %d\n", can_split(root3));

	struct s_node *root4 = 0;
	printf("Should be 0: %d\n", can_split(root4));
	return (0);
}