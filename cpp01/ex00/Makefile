NAME = zombie

CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

SRC = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

OBJ_FOLDER = object_files

OBJ_SRC = $(SRC:%.cpp=$(OBJ_FOLDER)/%.o)

# color
GREEN = \033[0;32m
RESET = \033[0m

all : $(NAME)

$(NAME) : $(OBJ_SRC)
	$(CC) $(CFLAGS) $(OBJ_SRC) -o $@
	@echo "${GREEN}-----COMPILED DONE-----\n${RESET}"

$(OBJ_FOLDER)/%.o : %.cpp | $(OBJ_FOLDER)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_FOLDER):
	@mkdir -p $(OBJ_FOLDER)

clean :
	rm -rf $(OBJ_FOLDER)

fclean : clean
	rm -f $(NAME)
	@echo "${GREEN}-----FULLY REMOVE-----\n${RESET}"

re : fclean all

leak :
	valgrind --leak-check=full ./$(NAME)

.PHONY: all clean fclean re leak