NAME = megaphone

CC = g++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = megaphone.cpp

OBJ_FOLDER = object_files

OBJ_SRC = $(addprefix $(OBJ_FOLDER)/, $(SRC:.cpp=.o))

all : $(NAME)

$(NAME) : $(OBJ_SRC)
	$(CC) $(CFLAGS) $(OBJ_SRC) -o $@

$(OBJ_FOLDER)/%.o : %.cpp | $(OBJ_FOLDER)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_FOLDER):
	@mkdir -p $(OBJ_FOLDER)

clean :
	rm -rf $(OBJ_FOLDER)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
