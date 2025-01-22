CC = cc
CFLAGS = -Wextra -Wall -Werror -Wunreachable-code
INCLUDES = -I ./include -I ./lib/MLX42/include

# export LIBRARY_PATH=/Users/abenajib/.brew/opt/glfw/lib
GLFW_PATH = $(shell brew --prefix glfw)
LDFLAGS = -L ./lib/MLX42/build -L $(GLFW_PATH)/lib -lmlx42 -lglfw -framework OpenGL -framework AppKit -ldl -pthread -lm

SRC = ./src/so_long.c \
		./src/map_parsing.c \
		./src/map_checkers.c \
		./src/map_checkers_2.c \
		./src/map_checkers_3.c \
		./src/game_init.c \
		./ft_printf/ft_printf.c \
		./ft_printf/ft_putchar_fd_p.c \
		./ft_printf/ft_putnbr_fd_p.c \
		./ft_printf/ft_putstr_fd_p.c \
		./ft_printf/ft_puthex_fd_p.c \
		./ft_printf/ft_putunint_fd_p.c \
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

TARGET = so_long

all: $(TARGET)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(TARGET): $(OBJ) libft ft_printf
	@$(CC) $(OBJ) ./libft/libft.a ./ft_printf/libftprintf.a $(LDFLAGS) -o $(TARGET)

clean:
	@rm -f $(OBJ)
	@make -C ./libft clean
	@make -C ./ft_printf clean

fclean: clean
	@rm -f $(TARGET)
	@make -C ./libft fclean
	@make -C ./ft_printf fclean

re: fclean all

# Build MLX42 library
mlx42:
	@cmake ./lib/MLX42 -B ./lib/MLX42/build
	@make -C ./lib/MLX42/build -j4

libft:
	@make -C libft

ft_printf:
	@make -C ft_printf

.PHONY: all clean fclean re mlx42 libft ft_printf
