SRC = *.cpp
NAME = Intern
CC = c++ -Wall -Wextra -Werror -std=c++98
RM = rm -rf
SHRUB = *_shrubbery
all: ${NAME}

${NAME}: ${SRC}
	${CC} ${SRC} -o ${NAME}

clean:
	${RM} ${NAME} ${SHRUB}

fclean: clean

re: fclean all