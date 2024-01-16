NAME	= fdf
SRC_DIR	= ./srcs/
SRCS	= main.c map.c key.c win.c init.c color.c
SRCS	:= $(addprefix $(SRC_DIR), $(SRCS))
OBJS	= $(SRCS:.c=.o)
LIB		= ./libft/libft.a
CC		= cc

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -Iincludes -c $< -o $@

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(OBJS) $(LIB) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

bonus: all

clean:
	rm -rf $(OBJS)
	make clean -C libft

fclean: clean
	rm -rf $(NAME) $(LIB)

re: fclean all

.PHONY: all clean fclean re bonus
