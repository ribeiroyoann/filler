/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoann <yoann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 13:53:48 by yoann             #+#    #+#             */
/*   Updated: 2019/01/23 17:14:08 by yoann            ###   ########.fr       */
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
	ft_strdel(&line);
	return (1);
}

int		get_board(t_parser *p)
{
	char	*line;
	int		y;

	if (!(get_next_line(0, &line)))
		return (0);
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
		p->board[y] = ft_strsub(line, 4, p->width);
		dprintf(2, "gnl %s\n", p->board[y]);
		y++;
	}
	return (0);
}

void	print_ogpiece(t_parser *p, char **piece)
{
	int		y;

	y = 0;
	while (y < p->piece_h)
	{
		dprintf(2, "%s\n", piece[y]);
		y++;
	}
}

void	get_piece(t_parser *p)
{
	char	*line;
	char	**stockpiece;
	int		y;

	get_next_line(0, &line);
	line += 6;
	p->piece_h = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	p->piece_w = ft_atoi(line);
	stockpiece = ft_memalloc(sizeof(char *) * p->piece_h + 1);
	y = 0;
	while (y < p->piece_h)
	{
		get_next_line(0, &line);
		stockpiece[y] = ft_strdup(line);
		y++;
	}
	print_ogpiece(p, stockpiece);
	dprintf(2, "------------\n");
	trim_piece(p, stockpiece);
}

