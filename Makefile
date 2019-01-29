# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/17 15:48:36 by yoribeir          #+#    #+#              #
#    Updated: 2019/01/29 15:46:51 by yoribeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = yoribeir.filler
INCLUDES = includes
LIBS = libft
LIB = ft
# FLAGS = -Wall -Werror -Wextra
SRCS = main.c parser.c utils.c player.c piece.c heatmap.c
SRCSREP = srcs
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: $(SRCSREP)/%.c
	gcc $(FLAGS) -I$(INCLUDES) -c $^

$(NAME): $(OBJS)
	@make -C libft
	gcc $(FLAGS) -I$(INCLUDES) $^ -L$(LIBS) -l$(LIB) -o $@

clean:
	rm -f $(OBJS)
	make clean -C libft
fclean: clean
	make fclean -C libft
	rm -f $(NAME)

test: all
	cp -f yoribeir.filler res/players
	./res/filler_vm -f ./res/maps/map00 -p2 ./res/players/hcao.filler -p1 ./res/players/yoribeir.filler 2>out -t 1

re: fclean all
