# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbarulls <gbarulls@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 18:02:47 by gbarulls          #+#    #+#              #
#    Updated: 2024/06/06 19:30:18 by gbaruls-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
LIBS		= includes/libft.h

SRC_DIR		=	srcs/
OBJ_DIR		=	objs/

SRCS_FILES	=	srcs/ft_putstr srcs/ft_putchar srcs/ft_strcmp srcs/ft_strlen srcs/ft_swap
SRCS 		= $(addsuffix .c, $(SRCS_FILES))
SRCDIRS		= $(shell find srcs/ -type d)
OBJSDIRS	= $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SRCDIRS))
OBJSTEMP	= $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SRCS_FILES))
OBJS		= $(addsuffix .o, $(OBJSTEMP))

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -Iincludes/
AR			= ar rcs
RANLIB		= ranlib
RM			= rm -rf
MKDIR		= mkdir -p

all:		$(NAME)

$(NAME):	$(OBJSDIRS) $(OBJS)
			$(AR) $(NAME) $(OBJS)
			$(RANLIB) $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(LIBS) Makefile
			$(CC) $(CFLAGS) -c $< -o $@

$(OBJSDIRS) :
	$(MKDIR) $(OBJSDIRS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(OBJSDIRS)
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re
