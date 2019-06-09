/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   volume_histogram.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 18:26:42 by exam              #+#    #+#             */
/*   Updated: 2019/01/07 19:46:00 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		count_all_not_zero(int * histo, int size)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (i < size)
	{
		if (histo[i] > 0)
			count++;
		i++;
	}
	return (count);
}

int    volume_histogram(int *histogram, int size)
{
	int	left;
	int right;
	int	pour_flag;
	int water;

	water = 0;
	while (count_all_not_zero(histogram, size) > 0)
	{
		left = 0;
		right = size - 1;
		pour_flag = 0;
		while (left < right)
		{
			if (histogram[left] > 0 && histogram[right] > 0)
			{
				pour_flag = 1;
				histogram[left] -= 1;
				histogram[right] -= 1;
				left++;
				right--;
			}
			else if (histogram[left] <= 0 && histogram[right] > 0)
			{
				if (pour_flag == 1)
					water += 1;
				left++;
			}
			else if (histogram[left] > 0 && histogram[right] <= 0)
			{
				if (pour_flag == 1)
					water += 1;
				right--;
			}
			else
			{
				if (pour_flag == 1)
					water += 2;
				left++;
				right--;
			}
		}
		if (left == right)
		{
			if (histogram[left] > 0)
				histogram[left] -= 1;
			else if (histogram[left] <= 0 && pour_flag == 1)
				water += 1;
		}
	}
	return (water);
}
