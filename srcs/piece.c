/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoann <yoann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:39:25 by yoann             #+#    #+#             */
/*   Updated: 2019/01/24 15:16:17 by yoann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		trim_height(t_parser *p, char **stockpiece)
{
	int		y;
	int		shift;

	y = 0;
	shift = 0;
	while (y < p->piece_h)
	{
		if (ft_strchr(stockpiece[y], '*'))
			return (shift);
		shift++;
		y++;
	}
	return (shift);
}

int		trim_width(t_parser *p, char **stockpiece)
{
	int		y;
	int		x;
	int		shift;

	shift = 0;
	x = 0;
	while (x < p->piece_w)
	{
		y = 0;
		while (y < p->piece_h)
		{
			if (stockpiece[y][x] == '*')
				return (shift);
			y++;
		}
		shift++;
		x++;
	}
	return (shift);
}

int		trim_height_end(t_parser *p, char **stockpiece)
{
	int		y;
	int		shift;

	y = p->piece_h - 1;
	shift = 0;
	while (y > 0)
	{
		if (ft_strchr(stockpiece[y], '*'))
			return (shift);
		shift++;
		y--;
	}
	return (shift);
}

int		trim_width_end(t_parser *p, char **stockpiece)
{
	int		y;
	int		x;
	int		shift;

	shift = 0;
	x = p->piece_w - 1;
	while (x >= 0)
	{
		y = p->piece_h - 1;
		while (y >= 0)
		{
			if (stockpiece[y][x] == '*')
				return (shift);
			y--;
		}
		shift++;
		x--;
	}
	return (shift);
}

void	get_shape(t_parser *p)
{
	int		y;
	int		x;

	dprintf(2, "PIECE %d %d\n", p->piece_h, p->piece_w);
	p->ey = 0;
	p->ex = 0;
	p->sy = p->piece_h;
	p->sx = p->piece_w;
	y = 0;
	while (y < p->piece_h)
	{
		x = 0;
		while (x < p->piece_w)
		{
			if (p->piece[y][x] == '*')
			{
				if (y > p->ey)
					p->ey = y;
				if (y < p->sy)
					p->sy = y;
				if (x > p->ex)
					p->ex = x;
				if (x < p->sx)
					p->sx = x;
			}
			x++;
		}
		y++;
	}
	p->psizey = p->ey - p->sy + 1;
	p->psizex = p->ex - p->sx + 1;
	print_piece(p, p->piece);
	dprintf(2, "PSIZE %d %d\n", p->psizey, p->psizex);
}