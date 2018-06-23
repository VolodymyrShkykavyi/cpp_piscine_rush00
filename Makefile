NAME = ft_retro
SRC = *.cpp
OBJ = $(SRC:.cpp=.o)
CC = clang++
FLAGS = -Wall -Werror -Wextra
INCLUDES = -lncurses

all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(INCLUDES)
%.o: %.cpp
	$(CC) $(FLAGS) -o $@ -c $<
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
