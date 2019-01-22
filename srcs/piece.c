/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoann <yoann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:39:25 by yoann             #+#    #+#             */
/*   Updated: 2019/01/22 14:26:11 by yoann            ###   ########.fr       */
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

void	trim_piece(t_parser *p, char **stockpiece)
{
	int		shift_h;
	int		shift_w;
	int		y;

	shift_h = trim_height(p, stockpiece);
	shift_w = trim_width(p, stockpiece);
	p->trim_h = p->piece_h - shift_h;
	p->trim_w = p->piece_w - shift_w;
	y = 0;
	p->piece = ft_memalloc(sizeof(char *) * p->trim_h + 1);
	while (y < p->trim_h)
	{
		p->piece[y] = ft_strdup(stockpiece[shift_h + y] + shift_w);
		y++;
	}
}