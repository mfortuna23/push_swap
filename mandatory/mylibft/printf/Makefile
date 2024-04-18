# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfortuna <mfortuna@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 12:23:34 by mfortuna          #+#    #+#              #
#    Updated: 2023/12/06 15:23:36 by mfortuna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= cc
CFLAGS	= -Wall -Werror -Wextra 
RM	= rm -rf
NAME	= libftprintf.a
OBJS	= ft_printf.o ft_nbr.o ft_printchar.o ft_printstr.o
AR	= ar rc
SRC = .	/files

all: $(NAME)

$(NAME) :$(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all
