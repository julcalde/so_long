NAME =			so_long

CFLAGS =		-Wall -Werror -Wextra -I./libft

HEADER	=		-I $(LIBMLX_DIR)/include -I $(LIBFT_DIR)/include

LIBFT_DIR =		libft
LIBFT =			$(LIBFT_DIR)/libft.a

LIBMLX_DIR =	MLX42
LIBMLX =		$(LIBMLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm

INCLUDE =		-I$(LIBMLX_DIR)/include -I header -I libft

SRCS =			main.c

OBJS =			$(SRCS:.c=.o)

all:			$(NAME)

$(NAME): $(OBJS) $(LIBFT) $(LIBMLX) $(HEADER)
	cc $(CFLAGS) $(OBJS) $(LIBFT) $(LIBMLX) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(LIBMLX):
	make -C $(LIBMLX_DIR)

%o: %c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(LIBMLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(LIBMLX_DIR) fclean

re: fclean all

.PHONY: all clean fclean re