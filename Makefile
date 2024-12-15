NAME =			so_long

CC =			cc
CFLAGS =		-Wall -Werror -Wextra -I./libft

HEADERS	=		-I $(LIBMLX_DIR)/include -I $(LIBFT_DIR)/include

LIBMLX_DIR =	./MLX42
LIBFT_DIR =		./libft

LIBMLX =		$(LIBMLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm
LIBFT =			$(LIBFT_DIR)/libft.a

SRCS =		

OBJS =			$(SRCS:.c=.o)

.SILENT:

all:	$(LIBFT) $(NAME)

$(LIBFT):
		make -C $(LIBFT_DIR)

libmlx: cmake $(LIBMLX_DIR) -B $(LIBMLX_DIR)/build
		make -C $(LIBMLX_DIR)/build -j4

$(NAME): $(OBJS) | $(LIBFT)
		$(CC) $(CFLAGS) $(OBJS) $(LIBMLX) $(LIBFT) $(HEADERS) \
		-framework Cocoa -framework OpenGL -framework IOKit -o $(NAME)

clean:
		rm -f $(OBJS)
		make -C $(LIBMLX_DIR)/build clean
		make -C $(LIBFT_DIR) clean

fclean: clean
		rm -f $(NAME)
		make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re