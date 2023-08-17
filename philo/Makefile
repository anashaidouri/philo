NAME = philo
CC = clang
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC	:=	srcs/death.c \
				srcs/forks.c \
				srcs/init.c \
				srcs/philo.c \
				srcs/threads.c \
				srcs/utils.c libft/ft_atoi.c

OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
# make -C libft/

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
