struct s_node {
	void *content;
	struct s_node *next;
};

int find_intersection(struct s_node *lst1_cur, struct s_node *lst2_head)
{
	while (lst2_head != 0)
	{
		if (lst2_head == lst1_cur)
			return (1);
		lst2_head = lst2_head->next;
	}
	return (0);
}

/*	Main idea:
	Looping list 2 to find if there's intersect on list 1
*/
void *intersection(struct s_node *lst1, struct s_node *lst2)
{
	while (lst1 != 0)
	{
		if (find_intersection(lst1, lst2))
			return (lst1);
		lst1 = lst1->next;
	}
	return (0);
}

// Test------------------------------------------------------------------ 
#include <stdlib.h>
#include <stdio.h>

void	print_list(struct s_node *head)
{
	while (head)
	{
		printf("(%p) -> ", head);
		head = head->next;
	}
	printf("\n");
}

struct s_node *new_node()
{
	struct s_node *new = malloc(sizeof(struct s_node));
	new->content = 0;
	new->next = 0;
	return (new);
}

int main(void)
{
	struct s_node *head1 = new_node();
	head1->next = new_node();
	head1->next->next = new_node();
	head1->next->next->next = new_node();
	head1->next->next->next->next = new_node();

	struct s_node *head2 = new_node();
	head2->next = new_node();
	head2->next->next = new_node();
	head2->next->next->next = new_node();
	head2->next->next->next->next = new_node();

	print_list(head1);
	printf("------------------------------------\n");
	print_list(head2);
	printf("------------------------------------\n");

	
	printf("No intersect: %p\n", intersection(head1, head2));

	head2->next->next->next->next->next = head1->next->next->next->next;
	printf("intersect: %p\n", intersection(head1, head2));
}