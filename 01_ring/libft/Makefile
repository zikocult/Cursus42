# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbaruls- <gbaruls-@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/11 11:42:44 by gbaruls-          #+#    #+#              #
#    Updated: 2024/06/11 13:35:47 by gbaruls-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
LIBS		= libft.h

SRCS_FILES	= $(shell find . -type f -iname "*.c" | sed 's#[.][^.]*$$##')

SRCS 		= $(addsuffix .c, $(SRCS_FILES))
OBJS		= $(addsuffix .o, $(SRCS_FILES))

CC		= gcc
CFLAGS		= -Wall -Wextra -Werror
AR		= ar rcs
RANLIB		= ranlib
RM		= rm -rf
MKDIR		= mkdir -p

all:		$(NAME)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)
			$(RANLIB) $(NAME)

%.o: %.c $(LIBS) Makefile
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

normi:
	@norminette $(SRCS)

info:
	$(info $(SRCS_FILES))
	$(info $(SRCS))
	$(info $(OBJS))

.PHONY:		all clean fclean re info normi
