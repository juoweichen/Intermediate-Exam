/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 09:20:40 by exam              #+#    #+#             */
/*   Updated: 2019/06/11 08:59:22 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct  s_point
{
	int           x;
	int           y;
}               t_point;

void  flood_fill(char **tab, t_point size, t_point begin)
{
	char place;

	if (tab == 0)
		return ;
	place = tab[begin.y][begin.x];
	tab[begin.y][begin.x] = 'F';
	if (begin.x + 1 < size.x && tab[begin.y][begin.x + 1] == place)
	{
		begin.x += 1;
		flood_fill(tab, size, begin);
		begin.x -= 1;
	}
	if (begin.x - 1 >= 0 && tab[begin.y][begin.x - 1] == place)
	{
		begin.x -= 1;
		flood_fill(tab, size, begin);
		begin.x += 1;
	}
	if (begin.y + 1 < size.y && tab[begin.y + 1][begin.x] == place)
	{
		begin.y += 1;
		flood_fill(tab, size, begin);
		begin.y -= 1;
	}
	if (begin.y - 1 >= 0 && tab[begin.y - 1][begin.x] == place)
	{
		begin.y -= 1;
		flood_fill(tab, size, begin);
		begin.y += 1;
	}
}

