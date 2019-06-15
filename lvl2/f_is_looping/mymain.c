# include <stdio.h>
# include <stdlib.h>

struct s_node {
	int value;
	struct s_node *next;
};

struct s_node *init_node(int value)
{
	struct s_node *newnode;

	newnode = (struct s_node *)malloc(sizeof(struct s_node));
	newnode->value = value;
	newnode->next = NULL;
	return newnode;
}	

int	is_looping(struct s_node *node);

int main(void)
{
	struct s_node *lst1;
	
	// lol
	lst1 = init_node(1);
	lst1->next = init_node(2);
	lst1->next->next = init_node(3);
	lst1->next->next->next = init_node(4);
	lst1->next->next->next->next = init_node(5);
	lst1->next->next->next->next->next = init_node(6);
	//loop list
	lst1->next->next->next->next->next->next = lst1->next->next;

	// No loop list
	struct s_node *lst2;
	lst2 = init_node(12);
	lst2->next = init_node(150);
	lst2->next->next = init_node(30);
	lst2->next->next->next = init_node(50);
	lst2->next->next->next->next = init_node(345);
	lst2->next->next->next->next->next = init_node(120);
	
	// loop list
	struct s_node *lst3;
	lst3 = init_node(12);
	lst3->next = init_node(19);
	lst3->next->next = init_node(14);
	lst3->next->next->next = lst3->next->next;
	/*
	// print list
	struct s_node *ptr = lst1;
	while(ptr)
	{
		printf("%d ->", ptr->value);
		ptr = ptr->next;
	}
	printf("\n");
	*/
	printf("is_looping: %d\n", is_looping(lst1));
	printf("is_looping: %d\n", is_looping(lst2));
	printf("is_looping: %d\n", is_looping(lst3));
	return (0);
}
