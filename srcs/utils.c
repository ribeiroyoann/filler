/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 18:21:38 by yoribeir          #+#    #+#             */
/*   Updated: 2019/03/27 18:24:30 by yoribeir         ###   ########.fr       */
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

void	ft_intdel(int **as)
{
	if (as)
	{
		free(*as);
		*as = NULL;
	}
}

void	free_2darray(t_parser *p, char **arr, int size)
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
		ft_intdel(&p->hmap[y]);
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

void	print_board(t_parser *p)
{
	int		y;

	y = 0;
	while (y < p->height)
	{
		dprintf(2, "%03d  %s\n", y, p->board[y]);
		y++;
	}
}

void	print_piece(t_parser *p, char **piece)
{
	int		y;

	y = 0;
	while (y < p->piece_h)
	{
		dprintf(2, "[%s]\n", piece[y]);
		y++;
	}
}
