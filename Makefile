# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoribeir <yoribeir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/17 15:48:36 by yoribeir          #+#    #+#              #
#    Updated: 2019/01/17 15:49:28 by yoribeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = yoribeir.filler
INCLUDES = includes
LIBS = libft
LIB = ft
FLAGS = -Wall -Werror -Wextra
SRCS = main.c
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
re: fclean all
