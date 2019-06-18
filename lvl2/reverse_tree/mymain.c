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

void print_tree(struct s_node *root)
{
	if (root == NULL)
		return ;
	printf("%d\n", root->value);
	print_tree(root->left);
	print_tree(root->right);
}

void reverse_tree(struct s_node *root);

int main(void)
{
	struct s_node* root1;
	root1 = init_node(94);
	root1->left = init_node(35);
	root1->right = init_node(52);
	root1->left->left = init_node(1);
	root1->left->right = init_node(9);
	root1->left->left->left = init_node(20);
	
	printf("Tree 1:\n");
	print_tree(root1);
	reverse_tree(root1);
	printf("Tree 1 reverse:\n");
	print_tree(root1);

	struct s_node *root2 = init_node(16);
	
	printf("Tree 2:\n");
	print_tree(root2);
	reverse_tree(root2);
	printf("Tree 2 reverse:\n");
	print_tree(root2);

	
	struct s_node *root3 = NULL;
	printf("Tree 3: \n");
	print_tree(root3);
	reverse_tree(root3);
	printf("Tree 3 reverse:\n");
	print_tree(root3);

	return (0);
}
