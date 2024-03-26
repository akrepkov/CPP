# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 14:31:45 by akrepkov          #+#    #+#              #
#    Updated: 2024/03/14 15:19:53 by akrepkov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = brain
CC = c++ 
C_FLAGS = -Wall -Werror -Wextra -std=c++98
SRC = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
OBJ_DIR = obj
HEADER = HumanA.hpp HumanB.hpp Weapon.hpp
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.cpp=%.o))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(C_FLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(C_FLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

PHONY := all, clean, re, fclean