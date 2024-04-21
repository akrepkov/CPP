
SRC = main.cpp Bureaucrat.cpp AForm.cpp \
	ShrubberyCreationForm.cpp \
	RobotomyRequestForm.cpp \
	PresidentialPardonForm.cpp \
	Intern.cpp
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.cpp=%.o))
CC = c++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror
HEADER = Bureaucrat.hpp AForm.hpp \
	ShrubberyCreationForm.hpp \
	RobotomyRequestForm.hpp \
	PresidentialPardonForm.hpp \
	Intern.hpp
NAME = bureaucrat

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
