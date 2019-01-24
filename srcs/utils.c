/* *******************************************************************p******* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoann <yoann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:15:27 by yoann             #+#    #+#             */
/*   Updated: 2019/01/22 13:30:29 by yoann            ###   ########.fr       */
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

// void	print_piece(t_parser *p, char **piece)
// {
// 	int		y;

// 	y = 0;
// 	while (y < p->psize_h)
// 	{
// 		dprintf(2, "-%s-\n", piece[y]);
// 		y++;
// 	}
// }
