/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 09:20:40 by exam              #+#    #+#             */
/*   Updated: 2019/06/04 10:19:51 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct  s_point
{
	int           x;
	int           y;
}               t_point;

void  flood_fill(char **tab, t_point size, t_point begin)
{
	if (tab == 0)
		return ;
	if (tab[begin.y][begin.x] != 'F')
	{
		tab[begin.y][begin.x] = 'F';
		flood_fill(tab, size, begin);
	}
	if (begin.x + 1 < size.x && tab[begin.y][begin.x + 1] != 'F')
	{
		begin.x += 1;
		flood_fill(tab, size, begin);
	}
	if (begin.x - 1 >= 0 && tab[begin.y][begin.x - 1] != 'F')
	{
		begin.x -= 1;
		flood_fill(tab, size, begin);
	}
	if (begin.y + 1 < size.y && tab[begin.y + 1][begin.x] != 'F')
	{
		begin.y += 1;
		flood_fill(tab, size, begin);
	}
	if (begin.y - 1 >= 0 && tab[begin.y - 1][begin.x] != 'F')
	{
		begin.y -= 1;
		flood_fill(tab, size, begin);
	}
}

