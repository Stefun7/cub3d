NAME = cub3d

INC = cub3d.h

CC = cc

CFLAGS = -Wall -Werror -Wextra -g -O0

SRCS = data_set.c debug.c free.c main.c map_set.c map_set2.c map_set3.c\
texture_set.c texture_set2.c utils.c utils2.c

OBJS = $(SRCS:.c=.o)

LIBFT = ./Libft/libft.a

all: $(NAME)

$(LIBFT):
	@make -C ./Libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) ${LIBFT} -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	rm -rf $(OBJS)
	@make clean -C ./Libft

fclean: clean
	rm -rf $(NAME)
	@make fclean -C ./Libft

re: fclean all

.PHONY: fclean clean all re
