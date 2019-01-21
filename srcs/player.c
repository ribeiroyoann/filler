/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoann <yoann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 19:53:09 by yoann             #+#    #+#             */
/*   Updated: 2019/01/21 20:25:26 by yoann            ###   ########.fr       */
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
	y = trim_height(p);
	while (y < p->piece_h)
	{
		x = trim_width(p);
		while (x < p->piece_w)
		{
			if (p->board[boardy + y])
		}
	}
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
			x++;
		}
		y++;
	}
}