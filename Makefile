# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbrandt <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/25 19:40:06 by bbrandt           #+#    #+#              #
#    Updated: 2016/11/29 13:51:56 by vkannema         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit

SRC = main.c read_and_check.c solver.c utility.c tetrimino.c 

OBJ = $(SRC:.c=.o)

FLAGS	= -Wall -Wextra -Werror

LIB_A = -L./Library/ -lft

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./Library/
	gcc $(FLAGS) $(OBJ) -I ./includes -o $(NAME) $(LIB_A)

%.o: %.c
	gcc $(FLAGS) -I ./includes/ -I ./Library/ -c $?

clean:
	rm -f $(OBJ)
	make clean -C ./Library/

fclean: clean
	rm -f $(NAME)
	make fclean -C ./Library/

re: fclean all

.PHONY : clean fclean re
