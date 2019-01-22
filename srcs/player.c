/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoann <yoann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 19:53:09 by yoann             #+#    #+#             */
/*   Updated: 2019/01/22 16:01:49 by yoann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_position(t_parser *p)
{
	int		y;
	int		x;

	y = 0;
	while (y < p->height)
	{
		x = 0;
		while (x < p->width)
		{
			if (p->board[y][x] == p->player)
				return (y * p->width + x);
			x++;
		}
		y++;
	}
	return (-1);
}

int		place_piece(t_parser *p, int boardy, int boardx)
{
	int		y;
	int		x;
	int		contact;

	contact = 0;
	y = 0;
	while (y < p->trim_h)
	{
		x = 0;
		while (x < p->trim_w)
		{
			if ((y + boardy > p->height) || (x + boardx > p->width))
				break ;
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
		dprintf(2, "CONTACT\n");
		return (1);
	}
	return (0);
}

int		solve(t_parser *p)
{
	int		y;
	int		x;

	y = 0;
	while (y < p->height)
	{
		x = 0;
		while (x < p->width)
		{
			dprintf(2, "%d %d\n", y, x);
			if (place_piece(p, y, x) == 1)
			{
				dprintf(2, "PLACE %d %d\n", y, x);
				printf("%d %d\n", y, x);
				// return (1);
			}
			x++;
		}
		y++;
	}
	printf("0 0\n");
	dprintf(2, "NO SOLVE\n");
	return (0);
}