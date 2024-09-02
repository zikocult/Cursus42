## ########################################################################## ##
##                                                                            ##
##                                                        :::      ::::::::   ##
##   Makefile                                           :+:      :+:    :+:   ##
##                                                    +:+ +:+         +:+     ##
##   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        ##
##                                                +#+#+#+#+#+   +#+           ##
##   Created: 2024/08/30 12:50:46 by Guillem Barulls   #+#    #+#             ##
##   Updated: 2024/08/30 17:57:17 by Guillem Barulls  ###   ########.fr       ##
##                                                                            ##
## ########################################################################## ##

NAME		=	../checker
PUSH		=	../push_swap
PUSH_SWAP	=	../include/push_swap.a
LIBFT		=	../libft/libft.a

SRC_DIR		= src/
OBJ_DIR		= obj/

SRCS_FILES	=	checker.c
OBJS		=	checker.o

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g
RM			= @rm -rf
MKDIR		= @mkdir -p

all:		$(NAME)

$(NAME):	$(PUSH) $(OBJSDIRS) $(OBJS) Makefile
			$(CC) $(CFLAGS) $(OBJS) $(PUSH_SWAP) $(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(LIBS) Makefile
			$(CC) $(CFLAGS) -c $< -o $@

$(OBJSDIRS):
			$(MKDIR) $(OBJSDIRS)

$(PUSH):
			make -C ../

clean:
			$(RM) $(OBJS)

fclean:		clean	
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re
