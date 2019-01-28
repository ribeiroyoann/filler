/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoann <yoann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 13:53:48 by yoann             #+#    #+#             */
/*   Updated: 2019/01/28 17:11:41 by yoann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_player(t_parser *p)
{
	char	*line;

	get_next_line(0, &line);
	if (line[10] == '1')
		p->player = 'O';
	else
		p->player = 'X';
	p->player = (line[10] == '1') ? 'O' : 'X';
	p->enemy = (p->player == 'O') ? 'X' : 'O';
	dprintf(2, "ME %c CPU %c\n", p->player, p->enemy);
	ft_strdel(&line);
	return (1);
}

int		get_board(t_parser *p)
{
	char	*line;
	int		y;

	get_next_line(0, &line);
	line += 8;
	if (!p->height)
		p->height = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	if (!p->width)
		p->width = ft_atoi(line);
	get_next_line(0, &line);
	p->board = ft_memalloc(sizeof(char *) * p->height + 1);
	y = 0;
	while (y < p->height)
	{
		get_next_line(0, &line);
		p->board[y] = ft_strdup(line + 4);
		y++;
	}
	create_inithmap(p);
	return (0);
}

void	get_piece(t_parser *p)
{
	char	*line;
	char	**ogpiece;
	int		y;

	get_next_line(0, &line);
	dprintf(2, "%s\n", line);
	line += 6;
	p->piece_h = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	p->piece_w = ft_atoi(line);
	ogpiece = ft_memalloc(sizeof(char *) * p->piece_h + 1);
	y = 0;
	while (y < p->piece_h)
	{
		get_next_line(0, &line);
		ogpiece[y] = ft_strdup(line);
		dprintf(2, "%s\n", ogpiece[y]);
		y++;
	}
	trim_piece(p, ogpiece);
}
