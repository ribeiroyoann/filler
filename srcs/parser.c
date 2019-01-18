/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoann <yoann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 13:53:48 by yoann             #+#    #+#             */
/*   Updated: 2019/01/18 16:31:16 by yoann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_player(t_parser *p)
{
	char	*line;

	get_next_line(0, &line);
	// dprintf(2, "%s", line);
	p->player = line[10] - '0';
	ft_strdel(&line);
	return (1);
}

int		get_board(t_parser *p)
{
	char	*line;
	int		y;

	get_next_line(0, &line);
	line += 8;
	p->height = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	p->width = ft_atoi(line);
	get_next_line(0, &line);
	p->board = malloc(sizeof(char *) * p->height + 1);
	y = 0;
	while (y < p->height)
	{
		get_next_line(0, &line);
		p->board[y] = ft_strsub(line, 4, p->width);
		y++;
	}
	printf("1 2\n");
	return (0);
}

void	get_piece(t_parser *p)
{
	char	*line;
	int		y;

	get_next_line(0, &line);
	line += 6;
	p->piece_h = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	p->piece_w = ft_atoi(line);
	p->piece = malloc(sizeof(char *) * p->piece_h + 1);
	y = 0;
	while (y < p->piece_h)
	{
		get_next_line(0, &line);
		p->piece[y] = ft_strdup(line);
		y++;
	}
}

int		parser(t_parser *p)
{
	get_player(p);
	get_board(p);
	get_piece(p);
	print_parsing(p);
	return (1);
}