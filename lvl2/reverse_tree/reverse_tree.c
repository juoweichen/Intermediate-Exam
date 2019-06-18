/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 20:41:25 by juochen           #+#    #+#             */
/*   Updated: 2019/06/15 21:50:25 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
	int           value;
	struct s_node *right;
	struct s_node *left;
};

void reverse_tree(struct s_node *root)
{
	struct s_node *tmp;

	if (root == 0)
		return ;
	reverse_tree(root->left);
	reverse_tree(root->right);
	tmp = root->left;
	root->left = root->right;
	root->right = tmp;
}
