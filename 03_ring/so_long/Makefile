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

NAME		= so_long
LIBS		= include/so_long.h
MINILIBX	= minilibx-linux/libmlx.a minilibx-linux/libmlx_Linux.a
MINILIBXINC = ./minilibx-linux
LIBFT		= libft/libft.a
LIBFTINC	= libft/include

SRC_DIR		=	src/
OBJ_DIR		=	obj/

SRCS_FILES	=	$(shell find src -type f -iname "*.c" | sed 's#[.][^.]*$$##')
# SRCS_FILES_INFO	=	$(shell find src -type f -iname "*.c" | sed 's#[.][^.]*$$##')
# SRCS_FILES	= src/test

SRCS 		= $(addsuffix .c, $(SRCS_FILES))
SRCDIRS		= $(shell find src/ -type d)
OBJSDIRS	= $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SRCDIRS))
OBJSTEMP	= $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SRCS_FILES))
OBJS		= $(addsuffix .o, $(OBJSTEMP))

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I$(LIBFTINC) -g
CFLAGSMLX	= -Lminilibx-linux -lmlx_Linux -lX11 -lXext
AR			= ar rcs
RANLIB		= ranlib
RM			= rm -rf
MKDIR		= mkdir -p

all:		$(NAME)

$(NAME):	$(MINILIBX) $(LIBFT) $(OBJSDIRS) $(OBJS) 
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(CFLAGSMLX) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(LIBS) Makefile
			$(CC) $(CFLAGS) -c $< $(CFLAGSMLX) -o $@

$(OBJSDIRS) :
	$(MKDIR) $(OBJSDIRS)

$(MINILIBX) : $(MINILIBXINC)
	make -C ./minilibx-linux

$(LIBFT) :
	make -C ./libft

$(MINILIBXINC) :
	tar -xvzf minilibx-linux.tgz

libs: $(MINILIBXINC)
	make -C ./minilibx-linux
	make -C ./libft

clean:
			$(RM) $(OBJS)
			make clean -C ./minilibx-linux
			make clean -C ./libft

fclean:		clean
			$(RM) $(OBJSDIRS)
			$(RM) $(NAME)
			rm -rf ./minilibx-linux
			make fclean -C ./libft

re:			fclean $(NAME)

normi:
	@norminette $(SRCS)
	@norminette $(LIBS)
	@make normi -C ./libft

info:
	$(info $(SRCS_FILES_INFO))
	$(info $(SRCS))
	$(info $(OBJS))

.PHONY:		all clean fclean re info normi libs

