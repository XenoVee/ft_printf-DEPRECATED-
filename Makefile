SOURCES = 
OBJECTS = $(SOURCES:.c=.o)
HEADER = ft_printf.h
CFLAGS = -Wall -Wextra -Werror -g
CC = gcc
NAME = ft_printf.a
TEST = test
SOURCES_TEST = main.c

all: $(NAME)

$(TEST): $(NAME) $(SOURCES_TEST)
	$(CC) -o $@ $^ 
	make clean

$(NAME): $(OBJECTS) $(HEADER)
	ar -rcsu $@ $^

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
