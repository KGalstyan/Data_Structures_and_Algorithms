NAME = sorting
CPP = g++
CPPFLAGS = -Wall -Wextra -Werror
SRC = main.cpp
# HEADER = 
OBJ_DIR = obj
OBJS = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp #$(HEADER)
	if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	if exist $(OBJ_DIR) rmdir /s /q $(OBJ_DIR)

fclean: clean
	if exist $(NAME).exe del $(NAME).exe

re: fclean all

.PHONY: all clean fclean re
