NAME = cub3d

INC = cub3d.h

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = $(wildcard *.c) #remove wilcard after !!!

OBJS = $(SRCS:.c=.o)

LIBFT = ./Libft/libft.a

all: $(NAME)

$(LIBFT):
	@make -C ./Libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) ${LIBFT} -o $(NAME)

%.o : %.c
	${CC} -I${INC} -c -o $@ $<

clean:
	rm -rf $(OBJS)
	@make clean -C ./Libft

fclean: clean
	rm -rf $(NAME)
	@make fclean -C ./Libft

re: fclean all

.PHONY: fclean clean all re