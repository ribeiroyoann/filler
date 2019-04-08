/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:56:11 by yoribeir          #+#    #+#             */
/*   Updated: 2019/04/08 14:37:28 by yoribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

#include <stdio.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

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
	int			heatscore;
	char		**board;
	int			**hmap;
	char		**piece;
}				t_parser;


/*
** PARSER
*/

int		get_player(t_parser *p);
int		get_board(t_parser *p);
int		get_piece(t_parser *p);
int		parser(t_parser *p);


/*
** PLAYER
*/

int		get_position(t_parser *p);
int		is_placeable(t_parser *p, int boardy, int boardx);
int		solve(t_parser *p);

/*
** PIECE
*/

int		trim_piece(t_parser *p, char **ogpiece);
void	get_shape(t_parser *p, char **ogpiece);


/*
** HEATMAP
*/

int		get_heatmap(t_parser *p);
void	print_hmap(t_parser *p);
void	fill_hmap(t_parser *p);

/*
** UTILS
*/

void	init_struct(t_parser *p);
void	print_board(t_parser *p);
void	print_piece(t_parser *p, char **piece);
void	print_parsing(t_parser *p);

void	free_piece(t_parser *p);
void	free_2darray(char **arr, int size);
void	free_hmap(t_parser *p);
void	ft_intdel(int **as);
int		ft_puterror(char *s);
void	print_result(t_parser *p);