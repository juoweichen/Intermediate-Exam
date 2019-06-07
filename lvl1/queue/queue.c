/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 09:16:33 by exam              #+#    #+#             */
/*   Updated: 2019/05/21 09:52:03 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct s_node {
	void *content;
	struct s_node *next;
};

struct s_queue {
	struct s_node *first;
	struct s_node *last;
};

struct s_node *init_node(void *content)
{
	struct s_node *new_node;

	new_node = (struct s_node *)malloc(sizeof(struct s_node));
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

struct s_queue *init(void)
{
	struct s_queue *new_queue;

	new_queue = (struct s_queue *)malloc(sizeof(struct s_queue));
	new_queue->first = NULL;
	new_queue->last = NULL;
	return (new_queue);
}

void enqueue(struct s_queue *queue, void *content)
{
	struct s_node *new;

	if (queue == NULL)
		return ;
	new = init_node(content);
	if (queue->last != NULL)
		queue->last->next = new;
	queue->last = new;
	if (queue->first == NULL)
		queue->first = new;
}

void *dequeue(struct s_queue *queue)
{
	struct s_node *ptr;
	void *content;

	if (queue == NULL || queue->first == NULL)
		return (NULL);
	ptr = queue->first;
	content = queue->first->content;
	queue->first = queue->first->next;
	free(ptr);
	return (content);
}

void *peek(struct s_queue *queue)
{
	if (queue == NULL || queue->first == NULL)
		return (NULL);
	return (queue->first->content);
}

int isEmpty(struct s_queue *queue)
{
	if (queue == NULL || queue->first == NULL)
		return (1);
	return (0);
}
