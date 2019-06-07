/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 09:20:40 by exam              #+#    #+#             */
/*   Updated: 2019/06/04 10:15:38 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  s_point
{
	int           x;
	int           y;
}               t_point;

void  flood_fill(char **tab, t_point size, t_point begin)

void print_tab(char **area, t_point size)
{
	int i;
	int j;

	i = 0;
	while (i < size.y)
	{
		j = 0;
		while (j < size.x)
		{
			printf("%c ", area[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

char **make_area(char **zone, t_point size)
{
	char **area;
	int i;

	area = (char **)malloc(sizeof(char *) * size.y);
	i = 0;
	while (i < size.y)
	{
		area[i] = (char *)malloc(sizeof(char) * size.x + 1);
		bzero(area[i], size.x + 1);
		strcpy(area[i], zone[i]);
		i++;
	}
	return (area);
}

int main(void)
{
	char **area;
	t_point size = {8, 5};
	t_point begin = {2, 3};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	area = make_area(zone, size);
	print_tab(area, size);
	flood_fill(area, size, begin);
	printf("\n");
	print_tab(area, size);
	return (0);
}

