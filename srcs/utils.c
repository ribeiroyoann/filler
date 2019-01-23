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

void	print_piece(t_parser *p, char **piece)
{
	int		y;

	y = 0;
	while (y < p->trim_h)
	{
		dprintf(2, "%s\n", piece[y]);
		y++;
	}
}
