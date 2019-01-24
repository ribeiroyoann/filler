/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoann <yoann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:56:11 by yoribeir          #+#    #+#             */
/*   Updated: 2019/01/24 19:44:43 by yoann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

#include <stdio.h>

typedef	struct s_parser
{
	char		player;
	char		enemy;
	int			height;
	int			width;
	int			piece_h;
	int			piece_w;
	int			sy;
	int			sx;
	int			ey;
	int			ex;
	int			psizey;
	int			psizex;
	int			pos_y;
	int			pos_x;
	char		**board;
	int			**hmap;
	char		**piece;
}				t_parser;


/*
** PARSER
*/

int		get_player(t_parser *p);
int		get_board(t_parser *p);
void	get_piece(t_parser *p);
int		parser(t_parser *p);


/*
** PLAYER
*/

int		get_position(t_parser *p);
int		place_piece(t_parser *p, int boardy, int boardx);
int		solve(t_parser *p);

/*
** PIECE
*/

void	get_shape(t_parser *p);


/*
** HEATMAP
*/

void	create_inithmap(t_parser *p);
void	print_hmap(t_parser *p);

/*
** UTILS
*/

void	init_struct(t_parser *p);
void	print_board(t_parser *p);
void	print_piece(t_parser *p, char **piece);
void	print_parsing(t_parser *p);