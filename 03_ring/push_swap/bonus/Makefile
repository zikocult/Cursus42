## ########################################################################## ##
##                                                                            ##
##                                                        :::      ::::::::   ##
##   Makefile                                           :+:      :+:    :+:   ##
##                                                    +:+ +:+         +:+     ##
##   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        ##
##                                                +#+#+#+#+#+   +#+           ##
##   Created: 2024/08/30 12:50:46 by Guillem Barulls   #+#    #+#             ##
##   Updated: 2024/09/05 17:51:43 by Guillem Barulls  ###   ########.fr       ##
##                                                                            ##
## ########################################################################## ##

NAME		= ../checker
PUSH		= ../push_swap
PUSH_SWAP	= ../include/push_swap.a
LIBFT		= ../libft/libft.a

SRC_DIR		= src/
OBJ_DIR		= obj/

SRCS_FILES	= checker.c
OBJS		= checker.o

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g
RM			= @rm -rf
NORM		= @norminette

.PHONY:		all clean fclean re normi push_swap libft

all:		libft push_swap $(NAME)

$(NAME):	$(PUSH) $(LIBFT) $(OBJS) Makefile
			$(CC) $(CFLAGS) $(OBJS) $(PUSH_SWAP) $(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(LIBS) Makefile
			$(CC) $(CFLAGS) -c $< -o $@

push_swap:
			make -C ../
libft:
			make -C ../libft/
clean:
			$(RM) $(OBJS)

fclean:		clean	
			$(RM) $(NAME)

re:			fclean $(NAME)

normi:		
			$(NORM)	$(SRCS_FILES)
