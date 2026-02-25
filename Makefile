INCLUDE = -I./include
CC = c++
CFLAGS = -std=c++98 -Wall -Werror -Wextra -Wshadow -g
NAME = PmergeMe

SRCS = main.cpp \
	srcs/PMergeMe.cpp

OBJ_DIR = obj

OBJ = $(SRCS:srcs/%.cpp=$(OBJ_DIR)/%.o)
OBJ := $(OBJ:main.cpp=$(OBJ_DIR)/main.o)

all: $(OBJ_DIR) $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: srcs/%.cpp  | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(INCLUDE) $< -o $@

$(OBJ_DIR)/main.o:main.cpp  |$(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re