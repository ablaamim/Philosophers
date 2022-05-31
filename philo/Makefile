# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 14:29:55 by ablaamim          #+#    #+#              #
#    Updated: 2022/05/31 22:51:13 by ablaamim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

HEADER = ../includes/philosophers.h

SRC = ./srcs/main.c \
	  ./srcs/ft_atoi.c \
	  ./srcs/ft_atol.c \
	  ./srcs/ft_init_args.c \
	  ./srcs/ft_isdigit.c \

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
