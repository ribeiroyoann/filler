/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:56:05 by yoribeir          #+#    #+#             */
/*   Updated: 2019/03/27 18:26:09 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(int argc, char **argv)
{
	t_parser	*p;

	p = malloc(sizeof(t_parser));
	init_struct(p);
	get_player(p);
	while (1)
	{
		get_board(p);
		get_heatmap(p);
		get_piece(p);
		if (!solve(p))
			break ;
		else
			dprintf(1, "%d %d\n", p->pos_y, p->pos_x);
	}
	free(p);
	// while (1);
	return (0);
}
