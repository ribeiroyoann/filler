/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoann <yoann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 19:53:09 by yoann             #+#    #+#             */
/*   Updated: 2019/01/28 18:12:15 by yoann            ###   ########.fr       */
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
	dprintf(2, "SCORE %d\n", score);
	dprintf(2, "HEATSCORE %d\n", p->heatscore);
	if (score < p->heatscore)
	{
		p->heatscore = score;
		dprintf(2, "COMPARE HEAT = %d - %d ; %d - %d\n", boardy, p->sy, boardx, p->sx);
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
				dprintf(2, "CONTACT %d %d\n", y, x);
				compare_heat(p, y, x);
				placeable = 1;
			}
		}
	}
	dprintf(2, "FINAL CONTACT %d %d\n", p->pos_y, p->pos_x);
	if (!placeable)
		return (0);
	dprintf(1, "%d %d\n", p->pos_y, p->pos_x);
	return (1);
}

// NEED FUNCTION TO RETURN 0 IF NOT PLACEABLE AT ALL
// COMPARE HEAT SEG FAULT