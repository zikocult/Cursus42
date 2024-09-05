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
BONUS		= checker
BONUS_DIR	= bonus/
LIBRARY		= include/push_swap.a
LIBS		= include/push_swap.h
LIBFT		= libft/libft.a
LIBFTINC	= libft/include
LIBFTD		= libft/.d

SRC_DIR		= src/
OBJ_DIR		= obj/

SRCS_FILES	= src/push_moves/push src/push_moves/rotate \
			  src/push_moves/reverse_rotate src/push_moves/swap \
			  src/turkey_sort/sort_utils src/turkey_sort/tiny_sorts \
			  src/turkey_sort/sort_init src/turkey_sort/turkey_sort \
			  src/init/utils src/init/free_error src/init/init_data \
			  src/init/init_med src/init/list_utils src/push_swap

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
MAKE_LIB	= ar -rcs

.PHONY:		all clean fclean re info normi bonus re_bonus

all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJSDIRS) $(OBJS) $(LIBRARY) Makefile
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(LIBS) Makefile
			$(CC) $(CFLAGS) -c $< -o $@

$(OBJSDIRS) :
			$(MKDIR) $(OBJSDIRS)

$(LIBFT):	$(LIBFTD)
			make -C ./libft

$(LIBFTD): $(shell find libft/ -type f)
			touch $(LIBFTD)

$(LIBRARY) : $(OBJS)
			$(MAKE_LIB) $(LIBRARY) $^

bonus:		
			make -C ./bonus

re_bonus: fclean bonus

clean:
			$(RM) $(OBJS)
			make clean -C ./libft
			make clean -C ./bonus

fclean:		
			$(RM) $(OBJSDIRS)
			$(RM) $(LIBRARY)
			$(RM) $(NAME)
			$(RM) $(LIBFTD)
			make fclean -C ./libft
			make fclean -C ./bonus

re:			fclean $(NAME)

normi:
			$(NORM) $(SRCS)
			$(NORM) $(LIBS)
			@make normi -C ./bonus

info:
			$(info $(SRCS_FILES))
