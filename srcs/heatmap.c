/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 19:35:36 by yoann             #+#    #+#             */
/*   Updated: 2019/03/28 17:02:33 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#define HEATMAP p->hmap[y][x]

void	surround_hmap(t_parser *p)
{
	int		y;
	int		x;

	y = 1;
	while (y < p->height - 1)
	{
		x = 1;
		while (x < p->width - 1)
		{
			if (p->hmap[y][x] == 0)
			{
				if (p->hmap[y][x + 1] == -2)
					p->hmap[y][x] = 1;
				if (p->hmap[y][x - 1] == -2)
					p->hmap[y][x] = 1;
				if (p->hmap[y + 1][x] == -2)
					p->hmap[y][x] = 1;
				if (p->hmap[y - 1][x] == -2)
					p->hmap[y][x] = 1;
			}
			x++;
		}
		y++;
	}
	fill_hmap(p);
}

void	assign_hmap(t_parser *p, int y, int x, int value)
{
	if (x + 1 < p->width)
	{
		if (p->hmap[y][x + 1] == value)
			HEATMAP = value + 1;
		if (y + 1 < p->height && p->hmap[y + 1][x + 1] == value)
			HEATMAP = value + 1;
		if (y - 1 >= 0 && p->hmap[y - 1][x + 1] == value)
			HEATMAP = value + 1;
	}
	if (x - 1 >= 0)
	{
		if (p->hmap[y][x - 1] == value)
			HEATMAP = value + 1;
		if (y - 1 >= 0 && p->hmap[y - 1][x - 1] == value)
			HEATMAP = value + 1;
		if (y + 1 < p->height && p->hmap[y + 1][x - 1] == value)
			HEATMAP = value + 1;
	}
	if (y + 1 < p->height && p->hmap[y + 1][x] == value)
		HEATMAP = value + 1;
	if (y - 1 >= 0 && p->hmap[y - 1][x] == value)
		HEATMAP = value + 1;
}

void	fill_hmap(t_parser *p)
{
	int		y;
	int		x;
	int		value;

	y = 0;
	value = 1;
	while (value < p->width)
	{
		while (y < p->height)
		{
			x = 0;
			while (x < p->width)
			{
				if (p->hmap[y][x] == 0)
					assign_hmap(p, y, x, value);
				x++;
			}
			y++;
		}
		y = 0;
		x = 0;
		value++;
	}
}

int		get_heatmap(t_parser *p)
{
	int		y;
	int		x;

	y = -1;
	if (!(p->hmap = malloc(sizeof(int *) * p->height + 1)))
		return (ft_puterror("Malloc error"));
	while (++y < p->height)
		if (!(p->hmap[y] = malloc(sizeof(int) * p->width + 1)))
			return (ft_puterror("Malloc error"));
	y = -1;
	while (++y < p->height)
	{
		x = -1;
		while (++x < p->width)
		{
			if (p->board[y][x] == '.')
				HEATMAP = 0;
			if (p->board[y][x] == p->player)
				HEATMAP = -1;
			if (p->board[y][x] == p->enemy)
				HEATMAP = -2;
		}
	}
	surround_hmap(p);
	return (1);
}

void	print_hmap(t_parser *p)
{
	int y;
	int x;

	y = 0;
	dprintf(2, "---------\n");
	while (y < p->height)
	{
		x = 0;
		while (x < p->width)
		{
			dprintf(2, "%d", p->hmap[y][x]);
			x++;
		}
		dprintf(2, "\n");
		y++;
	}
	dprintf(2, "\n");
}
