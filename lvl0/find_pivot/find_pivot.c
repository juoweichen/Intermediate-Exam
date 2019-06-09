/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 09:02:45 by exam              #+#    #+#             */
/*   Updated: 2019/06/08 20:54:35 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	find_pivot(int *arr, int n)
{
	int i;
	int sum;
	int lsum;

	sum = 0;
	// get sum of all numbers
	i = 0;
	while (i < n)
	{
		sum += arr[i];
		i++;
	}
	lsum = 0;
	// if left sum == right sum
	i = 0;
	while (i < n)
	{
		if (sum - arr[i] == 2 * lsum)
			return (i);
		lsum += arr[i];
		i++;
	}
	return (-1);
}
