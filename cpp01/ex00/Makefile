NAME=zombie
SRCS=main.cpp \
	Zombie.cpp \
	newZombie.cpp \
	randomChump.cpp
OBJS=$(SRCS:.cpp=.o)
CC=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
INCLUDE=-I.

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(INCLUDE) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

.PHONY: all clean fclean
