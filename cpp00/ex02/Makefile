NAME = test
CC = c++
C_FLAGS = -Wall -Werror -Wextra -std=c++98
SRC = tests.cpp Account.cpp
HEADER = Account.hpp
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

fclean: clean
	@rm -f $(NAME)

re: fclean all

PHONY := all, clean, re, fclean