# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pc <pc@student.42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/27 23:47:23 by pc                #+#    #+#              #
#    Updated: 2024/03/30 03:23:51 by pc               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM =rm -rf
SRC = philo.c\
		ft_isdigit.c\
		checker.c\
		error.c\
		ft_atoi.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
		@echo "MAKE IS COMPLETE"

clean:
	$(RM) $(OBJ)
	@echo "OBJ IS REMOVED"

fclean: clean
	$(RM) $(NAME)
	@echo "IT'S ALL CLEAN"

re: fclean all

.SILENT: