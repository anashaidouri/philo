# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahaidour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/08 15:30:15 by ahaidour          #+#    #+#              #
#    Updated: 2023/07/10 18:21:30 by ahaidour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
NAME_bonus = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = philo.c parsing.c utils.c

OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
