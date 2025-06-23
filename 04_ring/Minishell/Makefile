# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbaruls- <gbaruls-@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/06 16:54:00 by gbaruls-          #+#    #+#              #
#    Updated: 2025/05/12 16:12:40 by pamanzan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell
LIBS		= include/minishell.h
LIBINC		= include/
LIBFT		= mylibft/libft.a
LIBFTINC	= mylibft/include
LIBS_COM	= readline termcap
LIBS_COML	= $(addprefix -l, $(LIBS_COM))

SRC_DIR		= src/
OBJ_DIR		= obj/

SRCS_FILES	= $(shell find src -type f -iname "*.c" | sed 's#[.][^.]*$$##')

SRCS 		= $(addsuffix .c, $(SRCS_FILES))
SRCDIRS		= $(shell find src/ -type d)
OBJSDIRS	= $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SRCDIRS))
OBJSTEMP	= $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SRCS_FILES))
OBJS		= $(addsuffix .o, $(OBJSTEMP))

CC			= cc
CFLAGS		= -Wall -Wextra -Werror 
DFLAGS		= -g -fsanitize=address
AR			= ar rcs
RANLIB		= ranlib
RM			= rm -rf
MKDIR		= mkdir -p
LIBFTCOMP	= libft

.PHONY:		all clean fclean re info normi libft home libft_home

all:		$(LIBFTCOMP) $(NAME)

$(NAME):	$(LIBFT) $(OBJSDIRS) $(OBJS)
			$(CC) $(CFLAGS) $(DFLAGS) $(OBJS) $(LIBFT) $(LIBS_COML) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(LIBS) Makefile
			$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@

$(OBJSDIRS) : 
			$(MKDIR) $@

home:
		$(MAKE) CC=/usr/local/gcc-12.0.1/bin/gcc LIBFTCOMP=libft_home all

libft:
			make -C ./mylibft/

libft_home:
			make home -C ./mylibft/
			
$(LIBFT):	libft

clean:
			$(RM) $(OBJS)
			make clean -C ./mylibft/

fclean:		clean
			$(RM) $(OBJSDIRS)
			$(RM) $(NAME)
			make fclean -C ./mylibft/

re:			fclean all

normi:
			@norminette $(SRCS)

info:
			$(info $(OBJSDIRS))

