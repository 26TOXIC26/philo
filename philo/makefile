# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/27 23:47:23 by pc                #+#    #+#              #
#    Updated: 2024/05/07 15:10:29 by amousaid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -g -Wall -Werror -Wextra
RM =rm -rf
SRC = philo.c\
		ft_isdigit.c\
		checker.c\
		error.c\
		ft_atoi.c\
		born.c\
		time.c\
		life.c\
		print.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo " ┏━━━━━━━━━━━━━━━━━━━━━━┓"
	@echo "━┃      Building...     ┃━"
	@echo " ┗━━━━━━━━━━━━━━━━━━━━━━┛"

clean:
	$(RM) $(OBJ)
	@echo " ┏━━━━━━━━━━━━━━━━━━━━━━┓"
	@echo "━┃      Cleaning...     ┃━"
	@echo " ┗━━━━━━━━━━━━━━━━━━━━━━┛"

fclean: clean
	$(RM) $(NAME)
	@echo " ┏━━━━━━━━━━━━━━━━━━━━━━┓"
	@echo "━┃      Full clean...   ┃━"
	@echo " ┗━━━━━━━━━━━━━━━━━━━━━━┛"

re: fclean all

.SILENT: