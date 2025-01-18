CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS=	push_swap.c \
		./utils/push.c \
		./utils/swap.c \
		./utils/rotate.c \
		./utils/reverse_rotate.c \
		./utils/ft_validate.c \
		./utils/ft_sort_three.c \
		./utils/ft_sort_stack.c \
		./utils/helpers.c \
		./utils/finders.c \
		./utils/setters.c \
		./utils/ft_atoi.c \
		./utils/ft_isdigit.c \
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
NAME = push_swap.a
OBJS = $(SRCS:.c=.o)
HEADER = ./push_swap.h

all: push_swap

push_swap: $(NAME)
	@${CC} ${CFLAGS} -o push_swap push_swap.c $(NAME)
	@$(RM) $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $^

%.o: %.c $(HEADER)
	@${CC} ${CFLAGS} -c $< -o $@

bonus:
	@make -C checker_

clean:
	@$(RM) $(OBJS)
	@make -C checker_ clean

fclean: clean
	@$(RM) $(NAME) push_swap
	@make -C checker_ fclean

re: fclean all
