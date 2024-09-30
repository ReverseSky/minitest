# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grobledo <grobledo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/29 13:08:42 by greg              #+#    #+#              #
#    Updated: 2024/09/30 14:58:28 by grobledo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g
NAME	= cub3d
SRC		=	

OBJ		= $(SRC:.c=.o)

all		: ${NAME}

$(NAME)	: ${OBJ} 
		@echo "Compilation de ${NAME}"
		$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

%.o		: %.c
		@echo "Compilation des fichiers sources"
		$(CC) -c $< -o $@ $(CFLAGS) -I.

clean 	:
		@echo "Suppression des .o de ${NAME}"
		rm -rf $(OBJ)

fclean	:	clean
		@echo "Supression de l'executable..."
		rm -rf $(NAME)

re	:	fclean all

.PHONY:	all clean fclean re
