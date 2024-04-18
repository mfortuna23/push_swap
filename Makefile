# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfortuna <mfortuna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 11:57:58 by mfortuna          #+#    #+#              #
#    Updated: 2024/04/16 15:10:47 by mfortuna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.INCLUDEDIRS	: /mylibft /mandatory

CC				= cc
CFLAGS			= -Wall -Werror -Wextra 
RM				= rm -rf
NAME			= push_swap.a
MYLIBFT_PATH	= mandatory/mylibft/
NAMELIB			= mandatory/mylibft/mylibft.a
MANDATORY		= mandatory/
MAN_MAIN		= $(MANDATORY)main.c
PUSH_SWAPOBJ	= $(addprefix $(MANDATORY), stack_create.o errorcheck.o stack.o stack_sort.o stack_push_swap.o \
stack_rotate.o stack_sortall.o a_aftermove.o b_aftermove.o ft_nsplit.o)
AR				= ar rc
MAKE			= make -C

all: $(NAME)

$(NAME): $(NAMELIB) $(PUSH_SWAPOBJ)
	cp $(NAMELIB) $(NAME)
	$(AR) $(NAME) $(PUSH_SWAPOBJ) 
	$(CC) $(CFLAGS) -o push_swap $(MAN_MAIN) $(NAME)

$(NAMELIB) : $(MYLIBFT_PATH)
	$(MAKE) $(MYLIBFT_PATH)
	
$(MANDATORY)%.o: %.c
	$(CC) $(CFLAGS) -I . -c $<

clean:
	$(MAKE) $(MYLIBFT_PATH) clean
	$(RM) $(MANDATORY)*.o

fclean: clean
	$(MAKE) $(MYLIBFT_PATH) fclean
	$(RM) *.a
	$(RM) push_swap

re: fclean all
