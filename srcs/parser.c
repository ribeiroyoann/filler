/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 13:53:48 by yoann             #+#    #+#             */
/*   Updated: 2019/03/28 17:02:47 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_player(t_parser *p)
{
	char	*line;

	get_next_line(0, &line);
	if ((line[10] != '1' && line[10] != '0') || !line[10])
		return (ft_puterror("Player error"));
	if (line[10] == '1')
		p->player = 'O';
	else
		p->player = 'X';
	p->player = (line[10] == '1') ? 'O' : 'X';
	p->enemy = (p->player == 'O') ? 'X' : 'O';
	ft_strdel(&line);
	return (1);
}

int		create_board(t_parser *p)
{
	char	*line;
	int		y;

	if (!(p->board = ft_memalloc(sizeof(char *) * p->height + 1)))
		return (ft_puterror("Malloc error"));
	y = 0;
	while (y < p->height)
	{
		get_next_line(0, &line);
		if (!(p->board[y] = ft_strdup(line + 4)))
			return (ft_puterror("Malloc error"));
		ft_strdel(&line);
		y++;
	}
	ft_strdel(&line);
	return (1);
}

int		get_board(t_parser *p)
{
	char	*line;
	char	*tmp;

	if (get_next_line(0, &line) == -1)
		return (ft_puterror("GNL error"));
	tmp = line;
	line += 8;
	if (!p->height)
		p->height = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	if (!p->width)
		p->width = ft_atoi(line);
	ft_strdel(&tmp);
	if (get_next_line(0, &line) == -1)
		return (ft_puterror("GNL error"));
	ft_strdel(&line);
	create_board(p);
	return (1);
}

int		create_piece(t_parser *p)
{
	char	*line;
	char	**ogpiece;
	int		y;

	if (!(ogpiece = ft_memalloc(sizeof(char *) * p->piece_h + 1)))
		return (ft_puterror("Malloc error"));
	y = 0;
	while (y < p->piece_h)
	{
		if (get_next_line(0, &line) == -1)
			return (ft_puterror("GNL error"));
		if (!(ogpiece[y] = ft_strdup(line)))
			return (ft_puterror("Malloc error"));
		ft_strdel(&line);
		y++;
	}
	ft_strdel(&line);
	trim_piece(p, ogpiece);
	free_2darray(p, ogpiece, p->piece_h);
	return (1);
}

int		get_piece(t_parser *p)
{
	char	*line;
	char	*tmp;

	if (get_next_line(0, &line) == -1)
		return (ft_puterror("GNL error"));
	tmp = line;
	line += 6;
	p->piece_h = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	p->piece_w = ft_atoi(line);
	ft_strdel(&tmp);
	create_piece(p);
	return (1);
}
