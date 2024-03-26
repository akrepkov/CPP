NAME = zombie
CC = c++ 
C_FLAGS = -Wall -Werror -Wextra -std=c++98
SRC = Zombie.cpp zombieHorde.cpp main.cpp
HEADER = Zombie.hpp
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.cpp=%.o))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(C_FLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(C_FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@rm -rf $(OBJ_DIR)

test: all
	valgrind --leak-check=full ./zombie

fclean: clean
	@rm -f $(NAME)

re: fclean all

PHONY := all, clean, re, fclean