/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 18:21:38 by yoribeir          #+#    #+#             */
/*   Updated: 2019/04/08 14:37:22 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_struct(t_parser *p)
{
	p->player = 0;
	p->enemy = 0;
	p->height = 0;
	p->width = 0;
	p->piece_h = 0;
	p->piece_w = 0;
	p->pos_y = 0;
	p->pos_x = 0;
	p->board = 0;
	p->piece = 0;
	p->ey = 0;
	p->ex = 0;
	p->sx = 0;
	p->sy = 0;
	p->heatscore = 1000;
}

int		ft_puterror(char *s)
{
	ft_putendl_fd(s, 2);
	return (0);
}

void	free_2darray(char **arr, int size)
{
	int		y;

	y = 0;
	while (y < size)
	{
		ft_strdel(&arr[y]);
		y++;
	}
	free(arr);
}

void	free_hmap(t_parser *p)
{
	int		y;

	y = 0;
	while (y < p->height)
	{
		free(p->hmap[y]);
		p->hmap[y] = NULL;
		y++;
	}
	free(p->hmap);
}

void	free_piece(t_parser *p)
{
	int		y;

	y = 0;
	while (y < p->piece_h)
	{
		ft_strdel(&p->piece[y]);
		y++;
	}
	free(p->piece);
}
