#include <stdlib.h>

struct s_node
{
	int data;
	struct s_node *next;
	struct s_node *other;
};

struct s_node *new_node(int d)
{
	struct s_node *new = malloc(sizeof(struct s_node));
	new->data = d;
	new->next = 0;
	new->other = 0;
	return (new);
}

struct s_node *find_other(struct s_node *old_head, struct s_node *old_cur, \
	struct s_node *new_head)
{
	int index;

	// if no other, return null
	if (old_cur->other == 0)
		return 0;

	// find the current node other pointed index
	index = -1;
	while (old_head != 0)
	{
		index++;
		if (old_cur->other == old_head)
			break ;
		old_head = old_head->next;
	}

	// move new pointer to index node
	for (int i = 0; i < index; i++)
		new_head = new_head->next;
	return (new_head);
}

/*	Main idea:
	Subject describe other as "other pointer points to any node in the list (another node, itself or NULL)."
	Couldn't copy "other" straight to new clone list, otherwise new clone list "other" will point to old list node
	Need to create new list first, then find index of target node on old list, 
	Let new list "other" point it by index
*/
struct s_node *clone_list(struct s_node *node)
{
	struct s_node *newhead = new_node(node->data);
	struct s_node *old_ptr = node;
	struct s_node *new_ptr = newhead;

	// copy origin list except "other"
	old_ptr = old_ptr->next;
	while (old_ptr != 0)
	{
		new_ptr->next = new_node(old_ptr->data);
		new_ptr = new_ptr->next;
		old_ptr = old_ptr->next;
	}

	// find the index where "other" pointed to in each node, 
	// point the new node "other" to index to clone the behavior of origin list
	old_ptr = node;
	new_ptr = newhead;
	while (old_ptr != 0)
	{
		new_ptr->other = find_other(node, old_ptr, newhead);
		new_ptr = new_ptr->next;
		old_ptr = old_ptr->next;
	}
	return newhead;
}

// Test, credit by evandjohnston ----------------------------------------------------------
#include <stdio.h>

void	print_list(struct s_node *head)
{
	while (head)
	{
		printf("Node: %p\nData: %d\nOther: %p; ", head, head->data, head->other);
		if (head->other)
			printf("%d", head->other->data);
		printf("\n---\n");
		head = head->next;
	}
}

int		main(void)
{
	struct s_node *head = new_node(5);
	head->next = new_node(10);
	head->next->next = new_node(15);
	head->next->next->next = new_node(20);
	head->next->next->next->next = new_node(25);
	head->next->next->next->next->next = new_node(30);
	head->next->next->next->next->next->other = head->next->next->next->next; //30 -> 25
	head->next->next->next->next->other = head; //25 -> 5
	head->next->next->next->other = head->next; //20 -> 10
	head->next->next->other = head->next->next; //15 -> 15
	print_list(head);
	printf("\n\n");
	print_list(clone_list(head));
}