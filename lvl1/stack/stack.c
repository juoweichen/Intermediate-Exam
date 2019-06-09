/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 09:18:36 by exam              #+#    #+#             */
/*   Updated: 2019/06/08 20:57:43 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct s_node {
	void          *content;
	struct s_node *next;
};

struct s_stack {
	struct s_node *top;
};

struct s_node *init_node(void *content)
{
	struct s_node *new_node;

	new_node = (struct s_node *)malloc(sizeof(struct s_node));
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

struct s_stack *init(void)
{
	struct s_stack *new_stack;

	new_stack = (struct s_stack *)malloc(sizeof(struct s_stack));
	new_stack->top = NULL;
	return (new_stack);
}

void *pop(struct s_stack *stack)
{
	struct s_node *pop_node;
	void *pop_content;

	if (stack == NULL || stack->top == NULL)
		return (NULL);
	pop_node = stack->top;
	stack->top = stack->top->next;
	pop_content = pop_node->content;
	free(pop_node);
	return (pop_content);
}

void push(struct s_stack *stack, void *content)
{
	struct s_node *new_node;

	if (stack == NULL)
		return ;
	new_node = init_node(content);
	new_node->next = stack->top;
	stack->top = new_node;
}

void *peek(struct s_stack *stack)
{
	if (stack == NULL || stack->top == NULL)
		return (NULL);
	return (stack->top->content);
}

int isEmpty(struct s_stack *stack)
{
	if (stack == NULL || stack->top == NULL)
		return (1);
	return (0);
}
