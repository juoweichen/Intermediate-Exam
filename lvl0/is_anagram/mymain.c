/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 09:14:19 by exam              #+#    #+#             */
/*   Updated: 2019/04/09 09:18:44 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_anagram(char *a, char *b);

int main(void)
{
	char *a1 = "abcdef";
	char *b1 = "fabcde";
	printf("%d\n", is_anagram(a1, b1));

	char *a2 = ".123?.";
	char *b2 = "?321..";
	printf("%d\n", is_anagram(a2, b2));

	char *a3 = "abca";
	char *b3 = "bcab";
	printf("%d\n", is_anagram(a3, b3));
	
	return (0);
}
