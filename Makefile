SOURCES = ft_printf.c ft_printf_utils.c writes.c writes_pointer.c
OBJECTS = $(SOURCES:.c=.o)
HEADER = ft_printf.h
CFLAGS = -Wall -Wextra -Werror -g
CC = gcc
NAME = libftprintf.a
TEST = test
SOURCES_TEST = main.c

all: $(NAME)

$(TEST): $(NAME) $(SOURCES_TEST)
	@$(CC) -o $@ $^ -g
	@make clean

$(NAME): $(OBJECTS) $(HEADER)
	@ar -rcsu $@ $^

%.o: %.c
	@$(CC) -c $(CFLAGS) -o $@ $^

clean:
	@rm -f $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
