NAME=phonebook
SRCS= main.cpp \
	Contact.cpp \
	PhoneBook.cpp
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

re: fclean all

.PHONY: all clean fclean
