# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elel-yak <elel-yak@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/17 02:20:54 by elel-yak          #+#    #+#              #
#    Updated: 2023/08/07 22:25:23 by elel-yak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	philo.c utils.c msg_p.c life.c utils1.c finish.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=thread -g3 -o3 -pthread

RM = rm -rf
NAME = philo

all: $(NAME) clean 
$(NAME): $(OBJ)
	 $(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean all