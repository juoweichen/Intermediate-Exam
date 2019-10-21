#include <stdio.h>

#define NODE(value, left, right) &(struct s_node){value, left, right}

struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int	longest_sequence(struct s_node *node);

int	main(void)
{
/*
           10
           / \
          16  9
         / \   \
        /   \   \
       6     17  8
      / \         \
     /   \         \
    7   13          7
   /                 \
  /                   \
 8                     6

Longest sequence: 3 (6 -> 7 -> 8)
*/
	struct s_node *root1 = NODE(
		10,
		NODE(
			16,
			NODE(
				6,
				NODE(7, 
					NODE(8, NULL, NULL),
					NULL
					),
				NODE(13, NULL, NULL)
				),
			NODE(17, NULL, NULL)
			),
		NODE(
			9,
			NODE(
				8,
				NODE(
					7,
					NODE(6, NULL, NULL),
					NULL
					),
				NULL
				),
			NULL)
		);
	printf("Should be 3: %d\n", longest_sequence(root1));

	struct s_node *root2 = NULL;
	printf("Should be 0: %d\n", longest_sequence(root2));

	struct s_node *root3 = NODE(1, NODE(2, NODE(3, NODE(4, NULL, NULL), NULL), NULL), NULL);
	printf("Should be 4: %d\n", longest_sequence(root3));
}
