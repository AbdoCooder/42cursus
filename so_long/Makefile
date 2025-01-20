CC = cc
CFLAGS = -Wextra -Wall -Werror -Wunreachable-code
INCLUDES = -I ./include -I ./lib/MLX42/include

# export LIBRARY_PATH=/Users/abenajib/.brew/opt/glfw/lib
GLFW_PATH = $(shell brew --prefix glfw)
LDFLAGS = -L ./lib/MLX42/build -L $(GLFW_PATH)/lib -lmlx42 -lglfw -framework OpenGL -framework AppKit -ldl -pthread -lm

SRC = ./src/so_long.c \
		./src/map_parsing.c \
		./ft_printf/ft_printf.c \
		./ft_printf/ft_putchar_fd.c \
		./ft_printf/ft_putnbr_fd.c \
		./ft_printf/ft_putstr_fd.c \
		./ft_printf/ft_puthex_fd.c \
		./ft_printf/ft_putunint_fd.c \
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

TARGET = so_long

all: $(TARGET)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(TARGET): $(OBJ)
	@$(CC) $(OBJ) $(LDFLAGS) -o $(TARGET)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(TARGET)

re: fclean all

# Build MLX42 library
mlx42:
	@cmake ./lib/MLX42 -B ./lib/MLX42/build
	@make -C ./lib/MLX42/build -j4

.PHONY: all clean fclean re mlx42
