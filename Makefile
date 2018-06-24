NAME = ft_retro
SRC = Enemy.cpp EnemyAsteroid.cpp EnemyBoss.cpp EnemyShip.cpp Game.cpp Player.cpp Shoot.cpp main.cpp
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))
OBJ_DIR = objects
CC = clang++
FLAGS = -Wall -Werror -Wextra
INCLUDES = -lncurses $(ncursesw5-config --cflags --libs)

all: $(NAME)
$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(INCLUDES)
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
$(OBJ_DIR)/%.o: %.cpp
	$(CC) $(FLAGS) -o $@ -c $<
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
