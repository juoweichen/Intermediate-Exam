# include <stdio.h>
# include <stdlib.h>
# include <string.h>

struct s_node 
{
	int				value;
	struct s_node 	**nodes;
};

struct s_node *init_node(int value)
{
	struct s_node *new;

	new = (struct s_node *)malloc(sizeof(struct s_node));
	new->value = value;
	new->nodes = NULL;
	return new;
}

struct s_node **init_branch(int bsize)
{
	struct s_node **new;

	new = (struct s_node **)malloc(sizeof(struct s_node *) * (bsize + 1));
	bzero(new, sizeof(struct s_node *) * (bsize + 1));
	return new;
}

int height_tree(struct s_node *root);

int main(void)
{
	struct s_node *root;

	root = init_node(94);
	root->nodes = init_branch(2);
	root->nodes[0] = init_node(34);
	root->nodes[1] = init_node(52);
	root->nodes[0]->nodes = init_branch(2);
	root->nodes[0]->nodes[0] = init_node(1);
	root->nodes[0]->nodes[1] = init_node(99);
	root->nodes[1]->nodes = init_branch(1);
	root->nodes[1]->nodes[0] = init_node(11);
	root->nodes[1]->nodes[0]->nodes = init_branch(1);
	root->nodes[1]->nodes[0]->nodes[0] = init_node(13);
	// root->nodes[1]->nodes[0]->nodes[0]->nodes = init_branch(1);
	// root->nodes[1]->nodes[0]->nodes[0]->nodes[0] = init_node(28);
	
	printf("height_tree: %d\n", height_tree(root));
	return (0);
}

