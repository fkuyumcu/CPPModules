CPP = g++

FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = moar\

SRCS = main.cpp\
		zombieHorde.cpp\
		Zombie.cpp\
		
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