CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS=	push_swap.c push.c swap.c rotate.c reverse_rotate.c ft_validate.c ft_sort_three.c \
		ft_sort_stack.c helpers.c finders.c setters.c \
		./ft_printf/ft_putchar_fd_p.c ./ft_printf/ft_putnbr_fd_p.c ./ft_printf/ft_putstr_fd_p.c ./ft_printf/ft_printf.c \
		./ft_printf/ft_puthex_fd_p.c ./ft_printf/ft_putunint_fd_p.c \
		./libft/ft_isalpha.c ./libft/ft_isdigit.c ./libft/ft_isalnum.c ./libft/ft_isascii.c \
		./libft/ft_isprint.c ./libft/ft_strlen.c ./libft/ft_memset.c ./libft/ft_bzero.c \
		./libft/ft_memcpy.c ./libft/ft_memmove.c ./libft/ft_strlcpy.c ./libft/ft_strlcat.c \
		./libft/ft_calloc.c ./libft/ft_strdup.c ./libft/ft_toupper.c ./libft/ft_tolower.c \
		./libft/ft_strchr.c ./libft/ft_strncmp.c ./libft/ft_memchr.c ./libft/ft_memcmp.c \
		./libft/ft_strnstr.c ./libft/ft_atoi.c ./libft/ft_strrchr.c ./libft/ft_substr.c \
		./libft/ft_strjoin.c ./libft/ft_strtrim.c ./libft/ft_split.c ./libft/ft_itoa.c \
		./libft/ft_strmapi.c ./libft/ft_striteri.c ./libft/ft_putchar_fd.c \
		./libft/ft_putstr_fd.c ./libft/ft_putendl_fd.c ./libft/ft_putnbr_fd.c \
		./libft/ft_lstnew_bonus.c ./libft/ft_lstadd_front_bonus.c ./libft/ft_lstsize_bonus.c \
		./libft/ft_lstlast_bonus.c ./libft/ft_lstadd_back_bonus.c ./libft/ft_lstdelone_bonus.c \
		./libft/ft_lstclear_bonus.c ./libft/ft_lstiter_bonus.c ./libft/ft_lstmap_bonus.c \

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

.PHONY: clean
