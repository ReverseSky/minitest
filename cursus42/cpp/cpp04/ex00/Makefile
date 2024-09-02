SRC = *.cpp
NAME = Animal
CC = c++ -Wall -Wextra -Werror -std=c++98
RM = rm -rf

all: ${NAME}

${NAME}: ${SRC}
	${CC} ${SRC} -o ${NAME}

clean:
	${RM} ${NAME}

fclean: clean

re: fclean all