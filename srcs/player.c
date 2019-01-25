/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoann <yoann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 19:53:09 by yoann             #+#    #+#             */
/*   Updated: 2019/01/25 12:19:20 by yoann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

// int		calculate_heat(t_parser *p, int boardy, int boardx)
// {
// 	int		score;
// 	int		y;
// 	int		x;

// 	y = 0;
// 	while (y < p->piece_h)
// 	{

// 	}
// }

int		place_piece(t_parser *p, int boardy, int boardx)
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
	if (contact == 1)
	{
		dprintf(2, "CONTACT %d %d\n", boardy, boardx);
		return (1);
	}
	return (0);
}

int		solve(t_parser *p)
{
	int		y;
	int		x;

	y = -1;
	while (++y < p->height)
	{
		x = -1;
		while (++x < p->width)
		{
			if (place_piece(p, y, x) == 1)
			{
				dprintf(1, "%d %d\n", y - p->sy, x - p->sx);
				return (1);
			}
		}
	}
	return (0);
}