CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS=	push_swap.c \
		push.c \
		swap.c \
		rotate.c \
		reverse_rotate.c \
		ft_validate.c \
		ft_sort_three.c \
		ft_sort_stack.c \
		helpers.c \
		finders.c \
		setters.c \
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
		ft_atoi.c \
		ft_isdigit.c \
		./ft_split/ft_split.c \
		./ft_split/ft_strchr.c \
		./ft_split/ft_strdup.c \
		./ft_split/ft_strlen.c \
		./ft_split/ft_substr.c \

RM = rm -rf
NAME = push_swap.a
OBJS = $(SRCS:.c=.o)
HEADER = ./push_swap.h

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $^

%.o: %.c $(HEADER)
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
