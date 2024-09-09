## ########################################################################## ##
##                                                                            ##
##                                                        :::      ::::::::   ##
##   Makefile                                           :+:      :+:    :+:   ##
##                                                    +:+ +:+         +:+     ##
##   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        ##
##                                                +#+#+#+#+#+   +#+           ##
##   Created: 2024/08/30 12:50:46 by Guillem Barulls   #+#    #+#             ##
##   Updated: 2024/09/09 21:51:07 by Guillem Barulls  ###   ########.fr       ##
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

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf
NORM		= @norminette

.PHONY:		all clean fclean re normi push_swap libft

all:		push_swap $(NAME)

$(NAME):	$(PUSH) $(LIBFT) $(OBJS) Makefile
			$(CC) $(CFLAGS) $(OBJS) $(PUSH_SWAP) $(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c Makefile
			$(CC) $(CFLAGS) -c $< -o $@

push_swap:
			make library -C ../

clean:
			$(RM) $(OBJS)

fclean:		clean	
			$(RM) $(NAME)

re:			fclean all

normi:		
			$(NORM)	$(SRCS_FILES)
