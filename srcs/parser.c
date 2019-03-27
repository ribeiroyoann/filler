/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 13:53:48 by yoann             #+#    #+#             */
/*   Updated: 2019/03/27 18:23:20 by yoribeir         ###   ########.fr       */
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
	// dprintf(2, "ME %c CPU %c\n", p->player, p->enemy);
	ft_strdel(&line);
	return (1);
}

int		get_board(t_parser *p)
{
	char	*line;
	char	*tmp;
	int		y;

	get_next_line(0, &line);
	tmp = line;
	line += 8;
	if (!p->height)
		p->height = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	if (!p->width)
		p->width = ft_atoi(line);
	ft_strdel(&tmp);
	get_next_line(0, &line);
	ft_strdel(&line);
	p->board = ft_memalloc(sizeof(char *) * p->height + 1);
	y = 0;
	while (y < p->height)
	{
		get_next_line(0, &line);
		p->board[y] = ft_strdup(line + 4);
		ft_strdel(&line);
		y++;
	}
	ft_strdel(&line);
	return (1);
}

void	get_piece(t_parser *p)
{
	char	*line;
	char	*tmp;
	char	**ogpiece;
	int		y;

	get_next_line(0, &line);
	tmp = line;
	line += 6;
	p->piece_h = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	p->piece_w = ft_atoi(line);
	ft_strdel(&tmp);
	ogpiece = ft_memalloc(sizeof(char *) * p->piece_h + 1);
	y = 0;
	while (y < p->piece_h)
	{
		get_next_line(0, &line);
		ogpiece[y] = ft_strdup(line);
		ft_strdel(&line);
		y++;
	}
	ft_strdel(&line);
	trim_piece(p, ogpiece);
	free_2darray(p, ogpiece, p->piece_h);
}
