CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = ex02

SRCS = main.cpp\
		Cat.cpp\
		Dog.cpp\
		Animal.cpp\
		Brain.cpp\
		WrongAnimal.cpp\
		WrongCat.cpp
		
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(FLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	@$(CPP) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re