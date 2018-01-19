# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdavila <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/21 14:25:05 by rdavila           #+#    #+#              #
#    Updated: 2017/02/20 15:25:54 by rdavila          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Wextra -Werror
INCLUDES = -I libft/includes -I includes

SRC = main.c \
	  input.c \
	  print.c \
	  coordinates.c \
	  solver.c \
	  helpers.c \
	  generators.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/
	gcc $(FLAGS) $(INCLUDES) -c $(patsubst %, src/%, $(SRC))
	gcc $(FLAGS) $(INCLUDES) -o $(NAME) $(OBJ) -L libft/ -lft

clean:
	/bin/rm -f *.o
	make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
