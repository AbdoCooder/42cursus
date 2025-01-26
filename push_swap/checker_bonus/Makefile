CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS=	checker_bonus.c \
		checker_utils_bonus.c \
		checker_utils2_bonus.c \
		checker_utils3_bonus.c \
		ft_strcmp_bonus.c \
		./get_next_line_bonus/get_next_line_bonus.c \
		./get_next_line_bonus/get_next_line_utils_bonus.c \
		./ft_printf_bonus/ft_printf_bonus.c \
		./ft_printf_bonus/ft_putchar_fd_p_bonus.c \
		./ft_printf_bonus/ft_putnbr_fd_p_bonus.c \
		./ft_printf_bonus/ft_putstr_fd_p_bonus.c \
		./ft_printf_bonus/ft_puthex_fd_p_bonus.c \
		./ft_printf_bonus/ft_putunint_fd_p_bonus.c \
		./ft_lstutils_bonus/ft_lstadd_back_bonus.c \
		./ft_lstutils_bonus/ft_lstadd_front_bonus.c \
		./ft_lstutils_bonus/ft_lstclear_bonus.c \
		./ft_lstutils_bonus/ft_lstnew_bonus.c \
		./ft_lstutils_bonus/ft_lstsize_bonus.c \
		./ft_split_bonus/ft_split_bonus.c \
		./ft_split_bonus/ft_strchr_bonus.c \
		./ft_split_bonus/ft_strdup_bonus.c \
		./ft_split_bonus/ft_strlen_bonus.c \
		./ft_split_bonus/ft_substr_bonus.c \

RM = rm -rf
NAME = checker_bonus.a
OBJS = $(SRCS:.c=.o)
HEADER = checker_bonus.h

all: ../checker

../checker: $(NAME)
	@${CC} ${CFLAGS} -o ../checker checker_bonus.c $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $^

%.o: %.c $(HEADER)
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME) ../checker

re: fclean all

.PHONY: clean
