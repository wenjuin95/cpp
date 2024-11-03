NAME = megaphone

CC = g++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = megaphone.cpp

all :
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

fclean :
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
