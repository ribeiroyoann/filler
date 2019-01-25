/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoann <yoann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 19:53:09 by yoann             #+#    #+#             */
/*   Updated: 2019/01/25 13:43:45 by yoann            ###   ########.fr       */
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
			{
				score += p->hmap[y + boardy][x + boardx];
			}
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

	y = -1;
	p->heatscore = 0;
	while (++y < p->height)
	{
		x = -1;
		while (++x < p->width)
		{
			if (is_placeable(p, y, x) == 1)
			{
				// compare_heat(p, y, x);
				dprintf(2, "CONTACT %d %d\n", y - p->sy, x - p->sx);
				dprintf(1, "%d %d\n", y - p->sy, x - p->sx);
				return (1);
			}
		}
	}
	// dprintf(1, "%d %d\n", p->pos_y, p->pos_x);
	// dprintf(2, "FINAL %d %d\n", p->pos_y, p->pos_x);
	return (0);
}

// NEED FUNCTION TO RETURN 0 IF NOT PLACEABLE AT ALL
// COMPARE HEAT SEG FAULT