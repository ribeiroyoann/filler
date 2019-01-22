/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoann <yoann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:56:05 by yoribeir          #+#    #+#             */
/*   Updated: 2019/01/22 15:09:44 by yoann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(int argc, char **argv)
{
	t_parser	*p;

	p = malloc(sizeof(t_parser));
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
