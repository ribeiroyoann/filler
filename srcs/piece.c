/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoann <yoann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:39:25 by yoann             #+#    #+#             */
/*   Updated: 2019/01/23 16:43:08 by yoann            ###   ########.fr       */
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

char	*ft_strdup_until(char const *src, int until)
{
	char	*ret;
	int		i;

	ret = malloc(sizeof(char) * (until + 1));
	if (!ret)
		return (0);
	i = 0;
	while (src[i] && i <= until)
	{
		ret[i] = src[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}


void	trim_piece(t_parser *p, char **stockpiece)
{
	int		shift_h;
	int		shift_w;
	int		shift_endw;
	int		shift_endh;
	int		y;

	shift_h = trim_height(p, stockpiece);
	shift_w = trim_width(p, stockpiece);
	shift_endw = trim_width_end(p, stockpiece);
	if (shift_endw)
		shift_endw += 1;
	shift_endh = trim_height_end(p, stockpiece);
	p->trim_h = p->piece_h - shift_h;
	p->trim_w = p->piece_w - shift_w;
	y = 0;
	p->piece = ft_memalloc(sizeof(char *) * p->piece_h - shift_endh - shift_h + 1);
	while (y < p->piece_h - shift_endh - shift_h)
	{
		p->piece[y] = ft_strdup_until((stockpiece[shift_h + y] + shift_w), (p->piece_w - shift_endw - shift_w));
		p->psize_w = ft_strlen(p->piece[y]);
		dprintf(2, "[%s]\n", p->piece[y]);
		y++;
	}
	p->psize_h = y;
	// p->psize_w = p->piece_w - shift_endw - shift_w;
	dprintf(2, "PIECE SIZE %d %d\n", p->psize_h, p->psize_w);
}