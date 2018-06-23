NAME = ft_retro
SRC = *.cpp
OBJ = *.cpp
#OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))
OBJ_DIR = objects
CC = clang++
FLAGS = #-Wall -Werror -Wextra
INCLUDES = -lncurses

all: $(NAME)
$(NAME): #$(OBJ_DIR) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(INCLUDES)
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
$(OBJ_DIR)/%.o: %.cpp
#%.o: %.cpp
	$(CC) $(FLAGS) -o $@ -c $<
clean:
	rm -rf $(OBJ_DIR)
#	rmdir -p $(OBJ_DIR)
fclean: clean
	rm -f $(NAME)
re: fclean all
	./$(NAME)
