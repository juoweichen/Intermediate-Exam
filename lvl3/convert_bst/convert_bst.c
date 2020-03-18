/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_bst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 22:06:42 by juochen           #+#    #+#             */
/*   Updated: 2019/06/15 22:07:08 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
	int           value;
	struct s_node *right;
	struct s_node *left;
};

void recursion(struct s_node *cur, struct s_node **prev, struct s_node **head)
{
	if (cur == 0)
		return ;
	recursion(cur->left, prev, head);
	if (*prev)
		(*prev)->right = cur;
	else
		*head = cur;
	cur->left = *prev;
	*prev = cur;
	recursion(cur->right, prev, head);
}

/* Main idea
	Utilize another pointer call "prev", 
	keep tracking the previous node from current

	While travel to a node,
	point prev->right to cur, point cur->left to prev
		
    cur-> 88 
	     / \ 
	    /   \
prev-> 12   55 

   prev-> 88 
	     / \ 
	    /   \
	   12   55 <-cur

	head of doubly link list(dll) would be the node while prev is still null, 
	prev would only be null before place down to the smallest node

	circle head and tail of dll, the prev pointer will be the tail
*/
struct s_node *convert_bst(struct s_node *bst)
{
	struct s_node *prev = 0, *head = 0;

	recursion(bst, &prev, &head);
	// circle dll
	prev->right = head;
	head->left = prev;
	return head;
}

/* Test */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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

void print_dll(struct s_node *head)
{
	struct s_node *ptr;

	printf("%d->", head->value);
	ptr = head->right;
	while (ptr != head)
	{
		printf("%d->", ptr->value);
		ptr = ptr->right;
	}
	printf("\n");
}

int main(void)
{
	struct s_node *root1;
	
	root1 = init_node(10);
	root1->left = init_node(7);
	root1->right = init_node(15);
	root1->left->left = init_node(3);
	root1->left->right = init_node(8);
	root1->right->left = init_node(11);
	root1->right->right = init_node(17);

	struct s_node *head;

	head = convert_bst(root1);
	print_dll(head);
}

