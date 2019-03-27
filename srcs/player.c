/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 19:53:09 by yoann             #+#    #+#             */
/*   Updated: 2019/03/27 18:21:08 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		calculate_heat(t_parser *p, int boardy, int boardx)
{
	int		score;
	int		y;
	int		x;

	score = 0;
	y = 0;
	while (y < p->psizey)
	{
		x = 0;
		while (x < p->psizex)
		{
			if (p->piece[y][x] == '*')
				score += p->hmap[y + boardy][x + boardx];
			x++;
		}
		y++;
	}
	return (score);
}

void	compare_heat(t_parser *p, int boardy, int boardx)
{
	int		score;

	score = calculate_heat(p, boardy, boardx);
	if (score < p->heatscore)
	{
		p->heatscore = score;
		p->pos_y = boardy - p->sy;
		p->pos_x = boardx - p->sx;
	}
}


int		is_placeable(t_parser *p, int boardy, int boardx)
{
	int		y;
	int		x;
	int		contact;

	contact = 0;
	y = 0;
	if ((p->psizey + boardy > p->height) || (p->psizex + boardx > p->width))
		return (0);
	while (y < p->psizey)
	{
		x = 0;
		while (x < p->psizex)
		{
			if (p->piece[y][x] == '*' && p->board[y + boardy][x + boardx] == p->player)
				contact++;
			if (p->piece[y][x] == '*' && p->board[y + boardy][x + boardx] == p->enemy)
				return (0);
			x++;
		}
		y++;
	}
	return (contact == 1);
}

int		solve(t_parser *p)
{
	int		y;
	int		x;
	int  	placeable;

	p->heatscore = p->width * p->width;
	placeable = 0;
	y = -1;
	while (++y < p->height)
	{
		x = -1;
		while (++x < p->width)
		{
			if (is_placeable(p, y, x) == 1)
			{
				compare_heat(p, y, x);
				placeable = 1;
			}
		}
	}
	free_2darray(p, p->board, p->height);
	free_2darray(p, p->piece, p->psizey);
	free_hmap(p);
	if (!placeable)
		return (0);
	dprintf(1, "%d %d\n", p->pos_y, p->pos_x);
	return (1);
}
