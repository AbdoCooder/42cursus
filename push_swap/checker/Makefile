CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS=	checker.c \
		checker_utils.c \
		checker_utils2.c \
		checker_utils3.c \
		ft_strcmp.c \
		./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c \
		./ft_printf/ft_printf.c \
		./ft_printf/ft_putchar_fd_p.c \
		./ft_printf/ft_putnbr_fd_p.c \
		./ft_printf/ft_putstr_fd_p.c \
		./ft_printf/ft_puthex_fd_p.c \
		./ft_printf/ft_putunint_fd_p.c \
		./ft_lstutils/ft_lstadd_back_bonus.c \
		./ft_lstutils/ft_lstadd_front_bonus.c \
		./ft_lstutils/ft_lstclear_bonus.c \
		./ft_lstutils/ft_lstnew_bonus.c \
		./ft_lstutils/ft_lstsize_bonus.c \
		./ft_split/ft_split.c \
		./ft_split/ft_strchr.c \
		./ft_split/ft_strdup.c \
		./ft_split/ft_strlen.c \
		./ft_split/ft_substr.c \

RM = rm -rf
NAME = checker.a
OBJS = $(SRCS:.c=.o)
HEADER = ./checker.h

all: checker

checker: $(NAME)
	@${CC} ${CFLAGS} -o checker checker.c $(NAME)
	@RM $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $^

%.o: %.c $(HEADER)
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME) checker

re: fclean all
