# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbaruls- <gbaruls-@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/07 16:53:47 by gbaruls-          #+#    #+#              #
#    Updated: 2024/06/12 12:50:29 by gbaruls-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

SRCS 		= srcs/ft_putstr.c srcs/ft_putchar.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c
OBJS 		= srcs/ft_putstr.o srcs/ft_putchar.o srcs/ft_strcmp.o srcs/ft_strlen.o srcs/ft_swap.o

CC		= cc
CFLAGS		= -Wall -Werror -Wextra
AR		= ar rcs
RANLIB		= ranlib
RM		= rm -rf

all:		$(NAME)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)
			$(RANLIB) $(NAME)

%.o: %.c Makefile
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re
