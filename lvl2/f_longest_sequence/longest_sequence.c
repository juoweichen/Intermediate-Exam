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

# include <stdio.h>  // for test

struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

void tree_recursion(struct s_node *node, int *longest, int *current)
{
    if (!node)
        return ;
    if ((node->left && node->value + 1 == node->left->value) ||
        (node->right && node->value + 1 == node->right->value))
        *current = *current + 1;
    else
        *current = 1;
    *longest = (*current > *longest ? *current : *longest);
    tree_recursion(node->left, longest, current);
    tree_recursion(node->right, longest, current);
}

/*
    Record two values, current length and longest length
    current length will reset to 1 when sequence stop
    longest length keep update longest
    Travel the tree by pre-order to keep in track longest length
*/
int	longest_sequence(struct s_node *node)
{
    int longest = 0;
    int current = 1;

    tree_recursion(node, &longest, &current);
    return (longest);
}