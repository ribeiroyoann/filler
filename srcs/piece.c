/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:39:25 by yoann             #+#    #+#             */
/*   Updated: 2019/01/29 15:02:40 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	trim_piece(t_parser *p, char **ogpiece)
{
	int		y;
	int		x;

	get_shape(p, ogpiece);
	p->piece = ft_memalloc(sizeof(char *) * (p->psizey + 1));
	y = -1;
	while (++y < p->psizey)
		p->piece[y] = ft_memalloc(sizeof(char) * p->psizex + 1);
	y = 0;
	while (y < p->psizey)
	{
		p->piece[y] = ft_strnew(p->psizex);
		x = 0;
		while (x < p->psizex)
		{
			p->piece[y][x] = ogpiece[y + p->sy][x + p->sx];
			x++;
		}
		y++;
	}
}

void	get_shape(t_parser *p, char **ogpiece)
{
	int		y;
	int		x;

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
			x++;
		}
		y++;
	}
	p->psizey = p->ey - p->sy + 1;
	p->psizex = p->ex - p->sx + 1;
}