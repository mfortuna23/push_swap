# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfortuna <mfortuna@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/04 11:07:15 by mfortuna          #+#    #+#              #
#    Updated: 2023/12/06 15:47:51 by mfortuna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= cc
CFLAGS	= -Wall -Werror -Wextra 
RM	= rm -rf
NAME	= libft.a
OBJS	= ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_strlen.o \
ft_memset.o ft_bzero.o ft_memcpy.o ft_memmove.o ft_strlcpy.o ft_strlcat.o ft_toupper.o \
ft_tolower.o ft_strchr.o ft_strrchr.o ft_strncmp.o ft_memchr.o ft_memcmp.o ft_strnstr.o \
ft_atoi.o ft_calloc.o ft_strdup.o ft_substr.o ft_strjoin.o ft_strtrim.o ft_putchar_fd.o \
ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_itoa.o ft_split.o ft_strmapi.o ft_striteri.o \
ft_lstnew.o ft_lstadd_front.o ft_lstsize.o ft_lstlast.o ft_lstadd_back.o ft_lstdelone.o \
ft_lstclear.o ft_lstiter.o ft_lstmap.o
AR	= ar rc

all: $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

bonus: $(NAME) $(BONUS)
	$(AR) $(NAME) $(BONUS)
