/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 18:03:50 by exam              #+#    #+#             */
/*   Updated: 2019/01/11 19:05:01 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int height_tree(struct s_node *root)
{
	int height = 0;

	if (root == NULL)
		return (-1);
	
	while (*root->nodes != NULL)
	{
		height = height_tree(*root->nodes) + 1;
		root->nodes++;
	}
	return(height);
}
