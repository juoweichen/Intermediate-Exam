#include <stdio.h>

struct s_node {
	void          *content;
	struct s_node *next;
};

struct s_stack {
	struct s_node *top;
};

struct s_stack *init(void);
void *pop(struct s_stack *stack);
void push(struct s_stack *stack, void *content);
void *peek(struct s_stack *stack);
int isEmpty(struct s_stack *stack);

int main(void)
{
	struct s_stack *stack;

	stack = init();
	printf("isEmpty: %d\n", isEmpty(stack));

	push(stack, "Hi");
	push(stack, "my");
	push(stack, "name");
	push(stack, "is");
	push(stack, "Juo");

	printf("isEmpty: %d\n", isEmpty(stack));
	printf("peek: %s\n", peek(stack));

	printf("pop: %s\n", pop(stack));
	printf("pop: %s\n", pop(stack));
	printf("pop: %s\n", pop(stack));

	printf("isEmpty: %d\n", isEmpty(stack));
	printf("peek: %s\n", peek(stack));

	printf("pop: %s\n", pop(stack));
	printf("pop: %s\n", pop(stack));

	printf("isEmpty: %d\n", isEmpty(stack));
}
