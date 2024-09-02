SRC = *.cpp
NAME = DiamondTrap
CC = c++ -Wall -Wextra -Werror -Wshadow -Wno-shadow -std=c++98
RM = rm -rf

all: ${NAME}

${NAME}: ${SRC}
	${CC} ${SRC} -o ${NAME}

clean:
	${RM} ${NAME}

fclean: clean

re: fclean all