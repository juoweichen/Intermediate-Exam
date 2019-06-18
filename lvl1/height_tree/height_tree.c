/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 22:56:40 by juochen           #+#    #+#             */
/*   Updated: 2019/06/17 23:07:57 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */	

struct s_node {
	int           value;
	struct s_node **nodes;
};

int height_tree(struct s_node *root)
{
	int h;
	int heightest = -1;
	
	if (root == 0)
		return (-1);
	if (root->nodes == 0)
		return (0);
	for (int i = 0; root->nodes[i] != 0; i++)
	{
		h = height_tree(root->nodes[i]);
		if (h > heightest)
			heightest = h;
	}
	return (heightest + 1);
}
