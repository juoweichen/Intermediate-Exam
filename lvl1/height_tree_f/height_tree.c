/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 18:03:50 by exam              #+#    #+#             */
/*   Updated: 2019/06/11 10:44:26 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
	int           value;
	struct s_node **nodes;
};

int height_tree(struct s_node *root)
{
	int i = 0;
	int height = 0;
	int tmp = 0;

	if (root == 0)
		return (-1);
	if (root->nodes == 0)
		return (0);
	i = 0;
	while (root->nodes[i] != 0)
	{
		tmp = height_tree(root->nodes[i]) + 1;
		if (tmp > height)
			height = tmp;
		i++;
	}
	return (height);
}
