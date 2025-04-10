NAME = philo

SRC = init.c main.c utils.c philomanager.c utils2.c

OBJS = ${SRC:.c=.o}

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

obj : ${OBJS}

$(NAME): ${OBJS}
	gcc ${CFLAGS} $^ -o $@

clean :
	rm -f ${OBJS}

fclean : clean 
	rm -f $(NAME)
re : fclean all