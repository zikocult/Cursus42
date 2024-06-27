# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbarulls <gbarulls@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 18:02:47 by gbarulls          #+#    #+#              #
#    Updated: 2024/06/20 13:41:45 by gbaruls-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

LIB_DIR			= include/
LIBS			= include/ft_printf.h

SRC_DIR			= src/
SRCS_FILES		= src/ft_strings src/ft_number src/ft_pointer src/ft_printf
SRCS 			= $(addsuffix .c, $(SRCS_FILES))

OBJ_DIR			= obj/
OBJSTEMP		= $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SRCS_FILES))
OBJS			= $(addsuffix .o, $(OBJSTEMP))

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
AR				= ar rcs
RANLIB			= ranlib
RM				= rm -rf
MKDIR			= mkdir -p

all:			$(NAME)

$(NAME):		$(OBJ_DIR) $(OBJS)
				$(AR) $(NAME) $(OBJS)
				$(RANLIB) $(NAME)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(LIBS) Makefile
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR) :
				$(MKDIR) $(OBJ_DIR)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(OBJ_DIR)
				$(RM) $(NAME)

re:				fclean $(NAME)

normi:
				@norminette $(SRCS)
				@norminette $(LIBS)

info:
				$(info $(SRCS_FILES))
				$(info $(SRCDIRS))

.PHONY:			all clean fclean re info normi
