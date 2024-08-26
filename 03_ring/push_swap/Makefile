# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbaruls- <gbaruls-@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/06 16:54:00 by gbaruls-          #+#    #+#              #
#    Updated: 2024/04/06 17:26:17 by gbaruls-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap 
LIBS		= include/push_swap.h
LIBFT		= libft/libft.a
LIBFTINC	= libft/include

SRC_DIR		= src/
OBJ_DIR		= obj/

SRCS_FILES	=	$(shell find src -type f -iname "*.c" | sed 's#[.][^.]*$$##')

SRCS 		= $(addsuffix .c, $(SRCS_FILES))
SRCDIRS		= $(shell find src/ -type d)
OBJSDIRS	= $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SRCDIRS))
OBJSTEMP	= $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SRCS_FILES))
OBJS		= $(addsuffix .o, $(OBJSTEMP))

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I$(LIBFTINC) -g
RM			= @rm -rf
MKDIR		= @mkdir -p
NORM		= @norminette

all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJSDIRS) $(OBJS) Makefile
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(LIBS) Makefile
			$(CC) $(CFLAGS) -c $< -o $@

$(OBJSDIRS) :
			$(MKDIR) $(OBJSDIRS)

$(LIBFT) :	
			make -C ./libft

lib :		
			make -C ./libft

clean:
			$(RM) $(OBJS)
			make clean -C ./libft

fclean:		
			$(RM) $(OBJSDIRS)
			$(RM) $(NAME)
			make fclean -C ./libft

re:			fclean $(NAME)

normi:
			$(NORM) $(SRCS)
			$(NORM) $(LIBS)
			@make normi -C ./libft

info:
			$(info $(SRCS_FILES))

.PHONY:		all clean fclean re info normi lib
