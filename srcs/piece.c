/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:39:25 by yoann             #+#    #+#             */
/*   Updated: 2019/03/28 17:58:51 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		trim_piece(t_parser *p, char **ogpiece)
{
	int		y;
	int		x;

	p->ey = 0;
	p->ex = 0;
	get_shape(p, ogpiece);
	if (!(p->piece = ft_memalloc(sizeof(char *) * (p->psizey + 1))))
		return (ft_puterror("Malloc error"));
	y = 0;
	while (y < p->psizey)
	{
		if (!(p->piece[y] = ft_strnew(p->psizex)))
			return (ft_puterror("Malloc error"));
		x = 0;
		while (x < p->psizex)
		{
			p->piece[y][x] = ogpiece[y + p->sy][x + p->sx];
			x++;
		}
		y++;
	}
	return (1);
}

void	get_shape(t_parser *p, char **ogpiece)
{
	int		y;
	int		x;

	p->sy = p->piece_h;
	p->sx = p->piece_w;
	y = -1;
	while (++y < p->piece_h)
	{
		x = -1;
		while (++x < p->piece_w)
			if (ogpiece[y][x] == '*')
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
	}
	p->psizey = p->ey - p->sy + 1;
	p->psizex = p->ex - p->sx + 1;
}
