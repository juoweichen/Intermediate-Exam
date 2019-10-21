#include <stdlib.h>
#include <stdio.h>

struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int	longest_sequence(struct s_node *node);

struct s_node *newNode(int value)
{
	struct s_node *new = (struct s_node *)malloc(sizeof(struct s_node));
	new->value = value;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

int main(void)
{
	struct s_node *a = newNode(10);
	struct s_node *b = newNode(5);
	struct s_node *c = newNode(6);
	struct s_node *d = newNode(9);
	struct s_node *e = newNode(13);
	struct s_node *f = newNode(7);

	a->left = b;
	
	b->left = c;
	b->right = d;

	c->left = e;
	c->right = f;

	printf("longest = %d\n", longest_sequence(a));

	struct s_node *a1 = newNode(5);
	struct s_node *b1 = newNode(4);
	struct s_node *c1 = newNode(6);
	struct s_node *d1 = newNode(9);
	struct s_node *e1 = newNode(7);
	struct s_node *f1 = newNode(3);
	struct s_node *g1 = newNode(2);
	struct s_node *h1 = newNode(2);

	a1->left = b1;
	a1->right = c1;

	c1->left = d1;
	c1->right = e1;

	d1->left = f1;
	d1->right = g1;

	e1->right = h1;

	printf("longest = %d\n", longest_sequence(a1));

	struct s_node *a2 = newNode(30);
	struct s_node *b2 = newNode(15);
	struct s_node *c2 = newNode(41);
	struct s_node *d2 = newNode(61);
	struct s_node *e2 = newNode(80);

	a2->left = b2;
	a2->right = c2;

	b2->left = d2;

	c2->left = e2;

	printf("longest = %d\n", longest_sequence(a2));

	struct s_node *a3 = NULL;

	printf("longest = %d\n", longest_sequence(a3));

	return (0);
}
