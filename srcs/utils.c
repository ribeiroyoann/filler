/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoann <yoann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:15:27 by yoann             #+#    #+#             */
/*   Updated: 2019/01/18 16:19:52 by yoann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_board(t_parser *p)
{
	int		y;

	y = 0;
	while (y < p->height)
	{
		dprintf(2, "%s\n", p->board[y]);
		y++;
	}
}

void	print_piece(t_parser *p)
{
	int		y;

	y = 0;
	while (y < p->piece_h)
	{
		dprintf(2, "%s\n", p->piece[y]);
		y++;
	}
}

void	print_parsing(t_parser *p)
{
	dprintf(2, "Plateau %d %d\n", p->height, p->width);
	print_board(p);
	dprintf(2, "Piece %d %d\n", p->piece_h, p->piece_w);
	print_piece(p);
}