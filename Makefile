# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbixby <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/22 14:22:58 by bbixby            #+#    #+#              #
#    Updated: 2018/10/22 14:23:00 by bbixby           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = grimly
CFLAGS = -Wall -Werror -Wextra
RM = /bin/rm -rf
HEADER = grimly.h
CFILES = ./grimly.c ./grimly2.c ./verification.c ./maze.c ./maze2.c ./maze3.c ./libft.c ./queue.c
OFILES = $(CFILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OFILES)
	gcc $(CFLAGS) -I=$(HEADER) $(CFILES) -o $(NAME)
	# gcc -g -fsanitize=address -I=$(HEADER) $(CFILES) -o $(NAME)

clean:
	$(RM) $(OFILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re