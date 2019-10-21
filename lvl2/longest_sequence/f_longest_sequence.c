/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sequence.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 19:27:04 by juochen           #+#    #+#             */
/*   Updated: 2019/06/15 21:41:32 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//# include <stdio.h> for test

struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int	longest_sequence(struct s_node *node)
{
	int left;
	int right;
	int longest;

	if (!node)
		return (0);
	// printf("%d\n", node->value); print out tree	
	left = longest_sequence(node->left);
	right = longest_sequence(node->right);
	if ((node->left == 0 && node->right == 0))
		return (1); // most bottom node
	else if (node->right != 0 && node->right->value == node->value + 1)
		right++; // if right is a sequeance, right + 1 so right is right longest sequence
	else if(node->left != 0 && node->left->value == node->value + 1)
		left++; // same as right
	longest = (left > right ? left : right);
	return (longest);
}
