/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoann <yoann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:39:25 by yoann             #+#    #+#             */
/*   Updated: 2019/01/21 20:20:54 by yoann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		trim_height(t_parser *p)
{
	int		y;
	int		shift;

	y = 0;
	shift = 0;
	while (y < p->piece_h)
	{
		if (ft_strchr(p->piece[y], '*'))
			return (shift);
		shift++;
		y++;
	}
	return (shift);
}

int		trim_width(t_parser *p)
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
			if (p->piece[y][x] == '*')
				return (shift);
			y++;
		}
		shift++;
		x++;
	}
	return (shift);
}