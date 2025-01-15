NAME = phonebook

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 $(INC)

INC = -I include

SRC_FOLDER = src

SRC = $(wildcard $(SRC_FOLDER)/*.cpp)

OBJ_FOLDER = object_files

OBJ = $(SRC:$(SRC_FOLDER)/%.cpp=$(OBJ_FOLDER)/%.o)

# color
GREEN = \033[0;32m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@
	@echo "${GREEN}-----COMPILED DONE-----\n${RESET}"

$(OBJ_FOLDER)/%.o: $(SRC_FOLDER)/%.cpp | $(OBJ_FOLDER) #$(OBJ_FOLDER) is to check if the folder exists
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_FOLDER):
	@mkdir -p $(OBJ_FOLDER)

clean:
	rm -rf $(OBJ_FOLDER)

fclean: clean
	rm -f $(NAME)
	@echo "${GREEN}-----FULLY REMOVE-----\n${RESET}"

re: fclean all

.PHONY: all clean fclean re