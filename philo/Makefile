# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/24 17:53:02 by ablaamim          #+#    #+#              #
#    Updated: 2022/09/25 22:19:35 by ablaamim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
FLAGS = -Wall -Wextra -Werror #-fsanitize=thread -g3
RM = rm -rf

HEADER = ./includes/philosophers.h

SRC = ./sources/main.c \
	  ./sources/parser.c \
	  ./sources/tools.c \
	  ./sources/time_control.c \
	  ./sources/philo_life_cycle.c \
	  ./sources/actions_printer.c \


OBJ = $(patsubst %.c,%.o,$(SRC))


all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o:	%.c Makefile $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJ_B)

fclean:	clean
	$(RM) philo

re: fclean all

.PHONY: all clean fclean re bonus
