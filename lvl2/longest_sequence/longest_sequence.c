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

void tree_recursion(struct s_node *node, int *longest, int current)
{
    int cl, cr, cm;

    if (!node)
        return ;
    // update current right & current left
    cl = (node->left && node->value + 1 == node->left->value) ? current + 1 : 1;
    cr = (node->right && node->value + 1 == node->right->value) ? current + 1 : 1;
    // update longest
    cm = (cl > cr ? cl : cr);
    *longest = (cm > *longest ? cm : *longest);
    // tree travesal
    tree_recursion(node->left, longest, cl);
    tree_recursion(node->right, longest, cr);
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

    tree_recursion(node, &longest, current);
    return (longest);
}