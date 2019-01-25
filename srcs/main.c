/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoann <yoann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:56:05 by yoribeir          #+#    #+#             */
/*   Updated: 2019/01/25 12:09:14 by yoann            ###   ########.fr       */
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
		get_piece(p);
		if (!(solve(p)))
			return (0);
	}
	return (0);
}
