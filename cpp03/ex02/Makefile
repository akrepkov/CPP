
SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.cpp=%.o))
CC = c++
RM = rm -f
C_FLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow
HEADER = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp

NAME = claptrap

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(C_FLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(C_FLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean $(NAME)
