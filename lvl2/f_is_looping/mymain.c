#include <stdio.h>
#include <stdlib.h>

struct s_node {
	int value;
	struct s_node *next;
};

int	is_looping(struct s_node *node);

struct s_node *init_node(int value)
{
	struct s_node *newnode;

	newnode = (struct s_node *)malloc(sizeof(struct s_node));
	newnode->value = value;
	newnode->next = NULL;
	return newnode;
}

void print_list(struct s_node *node)
{
	struct s_node *ptr = node;

	while (ptr != NULL)
	{
		printf("%d-> ", ptr->value);
		ptr = ptr->next;
	}
}

int main(void)
{
	struct s_node *root = NULL;
	struct s_node *new = NULL;
	int i;

	// test NULL
	printf("is_looping: %d\n", is_looping(root));

	// create list
	i = 6;
	while (i > 0)
	{
		new = init_node(i);
		new->next = root;
		root = new;
		i--;
	}
	// check looping
	print_list(root);
	printf("is_looping: %d\n", is_looping(root));
	// move a pointer to last node
	struct s_node *end = root;
	while (end->next != 0)
		end = end->next;
	// make a loop
	end->next = root->next->next;
	// check looping
	//print_list(root);
	printf("is_looping: %d\n", is_looping(root));
}
