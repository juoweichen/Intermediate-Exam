/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_doublon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:58:28 by exam              #+#    #+#             */
/*   Updated: 2019/06/08 21:45:13 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
 *	Two array are sorted, by taking adventage of this, set each array a pointer or index
 *	if current element in first array is larger then the element in second array
 *	then move second array pointer forward till two elements are equal
 */
void	print_doublon(int *a, int na, int *b, int nb)
{
	int i;
	int j;
	int first_flag;

	if (a != 0 || b != 0)
	{
		i = 0;
		j = 0;
		first_flag = 0;
		while (i < na || j < na)
		{
			if (i == na)
				j++;
			else if (j == nb)
				i++;
			else if (a[i] == b[j])
			{
				if (first_flag == 0)
				{
					first_flag = 1;
					printf("%d", a[i]);
				}
				else
					printf(" %d", a[i]);
				i++;
				j++;
			}
			else if (a[i] > b[j])
				j++;
			else if (a[i] < b[j])
				i++;
		}
	}
	printf("\n");
}
