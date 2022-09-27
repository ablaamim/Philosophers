# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/24 17:53:02 by ablaamim          #+#    #+#              #
#    Updated: 2022/09/26 02:55:26 by ablaamim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

CC = gcc
FLAGS = -Wall -Wextra -Werror #-fsanitize=thread -g3
RM = rm -rf

HEADER = ./includes/philosophers_bonus.h

SRC = ./sources/main.c \
	  ./sources/parser_sem.c \
	  ./sources/philo_life_cycle.c \
	  ./sources/actions_printer.c \
	  ../philo/sources/parser.c \
	  ../philo/sources/tools.c \
	  ../philo/sources/time_control.c \


OBJ = $(patsubst %.c,%.o,$(SRC))


all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o:	%.c Makefile $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJ_B)

fclean:	clean
	$(RM) philo_bonus

re: fclean all

.PHONY: all clean fclean re bonus
