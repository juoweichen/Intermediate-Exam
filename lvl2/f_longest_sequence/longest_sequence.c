/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sequence.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 10:02:17 by exam              #+#    #+#             */
/*   Updated: 2019/02/19 11:09:22 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int	longest_sequence(struct s_node *node)
{
	if (node == 0)
		return (0);
	if (node->left == 0 && node->right == 0)
		return (1);

	int lc = 0;
	int rc = 0;

	if (node->left && node->value + 1 == node->left->value)
		lc = longest_sequence(node->left) + 1;
	else
		lc = longest_sequence(node->left);

	if (node->right && node->value + 1 == node->right->value)
		rc = longest_sequence(node->right) + 1;
	else
		rc = longest_sequence(node->right);

	return (rc > lc ? rc : lc);;
}
