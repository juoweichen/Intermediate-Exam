/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 09:24:59 by exam              #+#    #+#             */
/*   Updated: 2019/03/05 09:56:37 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc == 2 && argv[1] != NULL)
	{
		//turn all char to lower case
		int i = 0;
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				argv[1][i] += 32;
			i++;
		}

		//count
		int count[256];

		i = 0;
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
				count[(int)argv[1][i]]++;
			i++;
		}	

		//print and set to zero
		int first_flag = 0;

		i = 0;
		while (i < 256)
		{
			if (count[(int)argv[1][i]] != 0)
			{
				if (first_flag == 0)
				{
					printf("%d%c", count[(int)argv[1][i]], argv[1][i]);
					count[(int)argv[1][i]] = 0;
					first_flag = 1;
				}
				else
				{
					printf(", %d%c", count[(int)argv[1][i]], argv[1][i]);
					count[(int)argv[1][i]] = 0;
				}
			}
			i++;
		}
	}
	printf("\n");
	return (0);
}
