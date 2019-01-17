/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:56:05 by yoribeir          #+#    #+#             */
/*   Updated: 2019/01/17 16:21:00 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/filler.h"

int		main(int argc, char **argv)
{
	char *line;

	get_next_line(0, &line);
	if (line[10] == 1)
		dprintf(2, "PLAYER1");
	else
		dprintf(2, "PLAYER2");
	printf("1 1\n");
	return (0);
}
