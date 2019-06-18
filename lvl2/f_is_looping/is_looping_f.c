/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_looping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 18:35:56 by exam              #+#    #+#             */
/*   Updated: 2019/01/14 19:34:19 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
	int value;
	struct s_node *next;
};

int	is_looping(struct s_node *node)
{
	struct s_node loopNode;
	struct s_node *cur;
	struct s_node *prev;

	if (node == 0)
		return (0);
	// Give a very very rara number
	loopNode.value = -55667788;
	loopNode.next = 0;
	// iter all node in list, then point node to loopNode
	// WARNING: original list will been ruin
	prev = 0;
	cur = node;
	while (cur != 0)
	{
		if (cur->value == -55667788)
			return (1);
		prev = cur;
		cur = cur->next;
		prev->next = &loopNode;
	}
	return (0);
}
