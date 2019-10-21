# include <stdio.h>
# include <stdlib.h>

struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

struct s_node* init_node(int value)
{
	struct s_node *new;

	new = (struct s_node *)malloc(sizeof(struct s_node));
	new->value = value;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

int	longest_sequence(struct s_node *node);

int main(void)
{
	struct s_node* root1;

	root1 = init_node(10);
	root1->left = init_node(5);
	root1->left->left = init_node(6);
	root1->left->right = init_node(9);
	root1->left->left->left = init_node(7);
	root1->left->left->right = init_node(13);
	printf("longest: %d\n", longest_sequence(root1));	// 3

	struct s_node* root2;
	
	root2 = init_node(5);
	root2->left = init_node(6);
	root2->right = init_node(4);
	root2->right->left = init_node(9);
	root2->right->right = init_node(3);
	root2->right->left->left = init_node(3);
	root2->right->left->right = init_node(2);
	root2->right->right->right = init_node(2);
	printf("longest: %d\n", longest_sequence(root2));	// 2
	
	struct s_node* root3;
	
	root3 = init_node(30);
	root3->left = init_node(15);
	root3->right = init_node(41);
	root3->left->left = init_node(61);
	root3->right->left = init_node(80);
	printf("longest: %d\n", longest_sequence(root3));	// 1

	struct s_node *root4 = init_node(16);
	printf("longest: %d\n", longest_sequence(root4));	// 1

	struct s_node *root5 = NULL;	
	printf("longest: %d\n", longest_sequence(root5));	// 0

	struct s_node *root6;
	root6 = init_node(1);
	root6->left = init_node(2);
	root6->left->left = init_node(3);
	root6->left->left->left = init_node(4);
	root6->left->left->left->left = init_node(3);
	root6->left->left->left->left->left = init_node(4);
	printf("longest: %d\n", longest_sequence(root6));	// 4
	return (0);
}
