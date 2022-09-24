# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 14:29:55 by ablaamim          #+#    #+#              #
#    Updated: 2022/09/22 12:44:52 by ablaamim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

CC = gcc

FLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

RM = rm -rf

HEADER = ../includes/philosophers.h

SRC = ./sources/main.c \
	 ./sources/ft_parse_and_initialize.c \
	 ./sources/ft_routine_sem.c \
	 ./sources/philosophers_sem_simulation.c \
	 ./sources/sema_forks_and_philos_initializer.c \
	 ./sources/time_manager.c \
	 ./sources/actions_sem_philo.c \
	 ../philo/sources/time_control.c \
	 ../philo/sources/libft_utils.c \
	 ./sources/simulation_failed.c \

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
