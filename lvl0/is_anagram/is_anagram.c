/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_anagram.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 09:03:02 by exam              #+#    #+#             */
/*   Updated: 2019/04/09 09:14:14 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_anagram(char *a, char *b)
{
	char	count[127] = {0};
	int		i;

	//count a char
	i = 0;
	while (a[i] != '\0')
	{
		count[(int)a[i]] += 1;
		i++;
	}

	//substract count from b
	i = 0;
	while (b[i] != '\0')
	{
		count[(int)b[i]] -= 1;
		i++;
	}

	//check if count is all zero
	i = 0;
	while (i < 127)
	{
		if (count[i] != 0)
			return (0);
		i++;
	}
	return (1);
}
