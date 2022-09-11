# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 14:29:55 by ablaamim          #+#    #+#              #
#    Updated: 2022/09/11 15:48:34 by ablaamim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc

FLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

RM = rm -rf

HEADER = ../includes/philosophers.h

SRC = ./sources/main.c \
	  ./sources/initialize_and_parse_arguments.c \
	  ./sources/libft_utils.c \
	  ./sources/initialize_forks_and_philosophers.c \
	  ./sources/simulation_failed.c \
	  ./sources/action_philo.c \
	  ./sources/ft_routine.c \
	  ./sources/philosophers_simulation.c \
	  ./sources/time_control.c

OBJ = $(patsubst %.c,%.o,$(SRC))

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.c Makefile $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean :
	$(RM) philo $(OBJ)


re : fclean all

.PHONY : all clean fclean
