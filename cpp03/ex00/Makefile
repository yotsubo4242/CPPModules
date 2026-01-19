NAME=ClapTrap
SRCS=main.cpp \
	ClapTrap.cpp
OBJS=$(SRCS:.cpp=.o)
CXX=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
INCLUDE=-I.

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) $(INCLUDE) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(FLAGS) $(INCLUDE) -c $< -o $@

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
