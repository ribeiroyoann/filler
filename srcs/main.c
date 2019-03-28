/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:56:05 by yoribeir          #+#    #+#             */
/*   Updated: 2019/03/28 17:03:28 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(int argc, char **argv)
{
	t_parser	*p;

	if (!(p = malloc(sizeof(t_parser))))
		return (ft_puterror("Malloc error"));
	init_struct(p);
	if (!get_player(p))
		return (1);
	while (1)
	{
		if (!get_board(p))
			return (1);
		if (!get_heatmap(p))
			return (1);
		if (!get_piece(p))
			return (1);
		if (!solve(p))
			break ;
		else
			dprintf(1, "%d %d\n", p->pos_y, p->pos_x);
	}
	free(p);
	// while (1);
	return (0);
}
