/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_looping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 23:16:03 by juochen           #+#    #+#             */
/*   Updated: 2019/06/17 23:42:10 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node
{
	int value;
	struct s_node *next;
};

/*
	Set two pointers, fast and slow,
	fast move two nodes, slow move one node
	If fast catched up to slow means there's loop exist
*/
int is_looping(struct s_node *node)
{
	if (node == 0)
		return (0);

	struct s_node *slow = node;
	struct s_node *fast = node;

	while (fast != 0)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return (1);
	}
	return (0);
}
