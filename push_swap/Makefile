CC = cc
CFLAGS = -Wall -Wextra -Werror


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
