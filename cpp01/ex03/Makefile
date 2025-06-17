CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = violance\

SRCS = main.cpp\
		HumanA.cpp\
		HumanB.cpp\
		Weapon.cpp\
		
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