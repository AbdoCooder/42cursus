CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS=	./mandatory/pipex.c \
		./utils/ft_split/ft_split.c \
		./utils/ft_split/ft_strchr.c \
		./utils/ft_split/ft_strdup.c \
		./utils/ft_split/ft_strlen.c \
		./utils/ft_split/ft_substr.c \
		./utils/ft_strjoin/ft_strjoin.c \

RM = rm -rf
NAME = pipex.a
OBJS = $(SRCS:.c=.o)
HEADER = ./includes/pipex.h
TARGET = pipex

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

all: $(TARGET)

$(TARGET): $(NAME) $(HEADER) ./utils/ft_printf/libftprintf.a
	@${CC} ${CFLAGS} -o $(TARGET) ./mandatory/pipex.c $(NAME) ./utils/ft_printf/libftprintf.a
	@echo "$(GREEN)	______  _____ ______  _____ __   __"
	@echo "$(GREEN)| ___ \\|_   _|| ___ \\|  ___|\\ \\ / /"
	@echo "$(GREEN)| |_/ /  | |  | |_/ /| |__   \\ V /"
	@echo "$(GREEN)|  __/   | |  |  __/ |  __|  /   \\"
	@echo "$(GREEN)| |     _| |_ | |    | |___ / /^\\ \\"
	@echo "$(GREEN)\\_|     \\___/ \\_|    \\____/ \\/   \\/"
	@echo "$(GREEN)\n==The Makefile of [PIPEX] has been compiled!==\n$(DEF_COLOR)"
	@echo "$(YELLOW)\n=> Usage: ./pipex file1 cmd1 cmd2 file2\n$(DEF_COLOR)"

$(NAME): $(OBJS)
	@ar rcs $(NAME) $^

%.o: %.c $(HEADER)
	@${CC} ${CFLAGS} -c $< -o $@

# bonus:
#	@make -C bonus

clean:
	@$(RM) $(OBJS)
#	@make -C bonus clean
	@make --silent -C ./utils/ft_printf clean

fclean: clean
	@$(RM) $(NAME) pipex
#	@make -C bonus fclean
	@make --silent -C ./utils/ft_printf fclean

re: fclean all

./utils/ft_printf/libftprintf.a:
	@make --silent -C ./utils/ft_printf

.PHONY: clean
