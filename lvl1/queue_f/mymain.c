#include <stdio.h>

struct s_node {
	void          *content;
	struct s_node *next;
};

struct s_queue {
	struct s_node *first;
	struct s_node *last;
};

struct s_queue	*init(void);
void			enqueue(struct s_queue *queue, void *content);
void			*dequeue(struct s_queue *queue);
void			*peek(struct s_queue *queue);
int				isEmpty(struct s_queue *queue);


int main(void)
{
	struct s_queue *queue;

	queue = init();
	printf("isEmpty: %d\n", isEmpty(queue));

	enqueue(queue, "Hi");
	enqueue(queue, "my");
	enqueue(queue, "name");
	enqueue(queue, "is");
	enqueue(queue, "juo");
	
	printf("isEmpty: %d\n", isEmpty(queue));
	printf("peek: %s\n", peek(queue));

	printf("dequeue: %s\n", dequeue(queue));
	printf("dequeue: %s\n", dequeue(queue));
	printf("dequeue: %s\n", dequeue(queue));
	
	printf("isEmpty: %d\n", isEmpty(queue));
	printf("peek: %s\n", peek(queue));

	printf("dequeue: %s\n", dequeue(queue));
	printf("dequeue: %s\n", dequeue(queue));

	printf("isEmpty: %d\n", isEmpty(queue));

	printf("dequeue: %s\n", dequeue(queue));
	printf("isEmpty: %d\n", isEmpty(queue));
}
