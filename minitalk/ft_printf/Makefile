# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiboonpr <wiboonpr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/07 12:58:47 by wiboonpr          #+#    #+#              #
#    Updated: 2025/10/14 12:13:02 by wiboonpr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Wextra -Weror

AR = ar rcs

SRC = $(wildcard *.c)
OBJS = $(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean : 
	rm -f $(OBJS)

fclean :
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re