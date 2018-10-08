CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra
CXXXFLAGS = -Wall -Werror -Wextra -lncurses
NAME = ft_retro

SRC = Bullet.cpp I.cpp Entry.cpp Enemy.cpp main.cpp


OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all