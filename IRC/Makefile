SRC = srcs/Channel.class.cpp srcs/Client.class.cpp srcs/Commands.cpp srcs/Invite.cpp srcs/Join.cpp srcs/Kick.cpp srcs/Mode.cpp srcs/Nick.cpp srcs/ParseMessage.cpp srcs/Pass.cpp \
srcs/Server.class.cpp srcs/Server.cpp srcs/ServerDebug.cpp srcs/ServerLoop.cpp srcs/ServerUtils.cpp srcs/Topic.cpp srcs/User.cpp srcs/Utils.cpp main.cpp
NAME = irc
CC = c++ -Wall -Wextra -Werror -std=c++98
RM = rm -rf

all: ${NAME}

${NAME}: ${SRC}
	${CC} ${SRC} -o ${NAME}

clean:
	${RM} ${NAME}

fclean: clean

re: fclean all
