
SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp \
	WrongAnimal.cpp WrongCat.cpp WrongDog.cpp \
	Brain.cpp
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.cpp=%.o))
CC = c++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror
HEADER = Animal.hpp Cat.hpp Dog.hpp \
	WrongAnimal.hpp WrongCat.hpp WrongDog.hpp \
	Brain.hpp

NAME = animal

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CPPFLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: %.cpp  $(HEADER)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CPPFLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean $(NAME)
