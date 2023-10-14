# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbarulls <gbarulls@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 18:02:47 by gbarulls          #+#    #+#              #
#    Updated: 2023/05/29 20:08:51 by gbarulls         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
LIBS		= libft.h

SRC_DIR		=	src/
OBJ_DIR		=	obj/

SRCS_FILES	=	$(shell find src -type f -iname "*.c" | sed 's#[.][^.]*$$##')

SRCS 		= $(addsuffix .c, $(SRCS_FILES))
SRCDIRS		= $(shell find src/ -type d)
OBJSDIRS	= $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SRCDIRS))
OBJSTEMP	= $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SRCS_FILES))
OBJS		= $(addsuffix .o, $(OBJSTEMP))

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I.
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

normi:
	@norminette $(SRCS)

info:
	$(info $(SRCS_FILES))

.PHONY:		all clean fclean re info normi
