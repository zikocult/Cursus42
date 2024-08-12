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

SRC_DIR		= src/
OBJ_DIR		= obj/

SRCS_FILES	= src/init_graph src/init_map src/move src/so_long src/check_path \
			  src/frees src/check_map

SRCS 		= $(addsuffix .c, $(SRCS_FILES))
SRCDIRS		= $(shell find src/ -type d)
OBJSDIRS	= $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SRCDIRS))
OBJSTEMP	= $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SRCS_FILES))
OBJS		= $(addsuffix .o, $(OBJSTEMP))

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I$(LIBFTINC)
CFLAGSMLX	= -Lminilibx-linux -lmlx_Linux -lX11 -lXext
AR			= ar rcs
RANLIB		= ranlib
RM			= rm -rf
TAR			= tar -xvzf
MKDIR		= mkdir -p
NORM		= @norminette

all:		$(NAME)

$(NAME):	$(MINILIBX) $(LIBFT) $(OBJSDIRS) $(OBJS) Makefile
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(CFLAGSMLX) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(LIBS) Makefile
			$(CC) $(CFLAGS) -c $< $(CFLAGSMLX) -o $@

$(OBJSDIRS) :
			$(MKDIR) $(OBJSDIRS)

$(MINILIBX) : $(MINILIBXINC)
			make -C $(MINILIBXINC)

$(LIBFT) :
			make -C ./libft

$(MINILIBXINC) :
			$(TAR) minilibx-linux.tgz
			$(RM) $(MINILIBXINC)/.git/
			$(RM) $(MINILIBXINC)/.github/
			$(RM) $(MINILIBXINC)/man/
			$(RM) $(MINILIBXINC)/.gitignore

libs: $(MINILIBXINC)
			make -C $(MINILIBXINC)
			make -C ./libft

clean:
			$(RM) $(OBJS)
			make clean -C ./minilibx-linux
			make clean -C ./libft

fclean:		
			$(RM) $(OBJSDIRS)
			$(RM) $(NAME)
			$(RM) ./minilibx-linux
			make fclean -C ./libft

re:			fclean $(NAME)

normi:
			$(NORM) $(SRCS)
			$(NORM) $(LIBS)
			@make normi -C ./libft

info:
			$(info $(SRCS_FILES))

.PHONY:		all clean fclean re info normi libs

