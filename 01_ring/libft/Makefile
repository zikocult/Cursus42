# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbaruls- <gbaruls-@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 15:32:50 by gbaruls-          #+#    #+#              #
#    Updated: 2024/06/28 18:17:33 by gbaruls-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ_DIR			= obj/

NAME			= libft.a
BONUS			= obj/.bonus
LIBS			= libft.h

SRC_DIR			= src/
SRCS_FILES		= src/ft_strchr src/ft_strdup src/ft_striteri src/ft_strjoin \
			  	src/ft_strlcat src/ft_strlcpy src/ft_strlen src/ft_strmapi \
			  	src/ft_strncmp src/ft_strnstr src/ft_strrchr src/ft_strtrim \
			  	src/ft_substr src/ft_tolower src/ft_toupper src/ft_atoi \
			  	src/ft_bzero src/ft_calloc src/ft_isalnum src/ft_isalpha \
			  	src/ft_isascii src/ft_isdigit src/ft_isprint src/ft_itoa \
			  	src/ft_memchr src/ft_memcmp src/ft_memcpy src/ft_memmove \
			  	src/ft_memset src/ft_putchar_fd src/ft_putendl_fd src/ft_putnbr_fd \
			  	src/ft_putstr_fd src/ft_split

SRCS 			= $(addsuffix .c, $(SRCS_FILES))
OBJSTEMP		= $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SRCS_FILES))
OBJS			= $(addsuffix .o, $(OBJSTEMP))

BONUS_DIR		= bonus/
BONUS_FILES		= bonus/ft_lstadd_back_bonus bonus/ft_lstadd_front_bonus bonus/ft_lstclear_bonus \
			  	  bonus/ft_lstdelone_bonus bonus/ft_lstiter_bonus bonus/ft_lstlast_bonus \
			  	  bonus/ft_lstmap_bonus bonus/ft_lstnew_bonus bonus/ft_lstsize_bonus

BONUS_SRCS 		= $(addsuffix .c, $(BONUS_FILES))
B_OBJSTEMP		= $(patsubst $(BONUS_DIR)%,$(OBJ_DIR)%,$(BONUS_FILES))
BONUS_OBJS		= $(addsuffix .o, $(B_OBJSTEMP))

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
AR				= ar rcs
RANLIB			= ranlib
RM				= rm -rf
MKDIR			= mkdir -p
TOUCH			= touch

all:			$(NAME)

$(NAME):		$(OBJ_DIR) $(OBJS)
				$(AR) $(NAME) $(OBJS)
				$(RANLIB) $(NAME)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c $(LIBS) Makefile
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR) :
				$(MKDIR) $(OBJ_DIR)

bonus:			$(BONUS)

$(BONUS):		$(OBJ_DIR) $(BONUS_OBJS) $(OBJS)
				$(AR) $(NAME) $(BONUS_OBJS) $(OBJS)
				$(RANLIB) $(NAME)
				@$(TOUCH) $(BONUS)

$(OBJ_DIR)%.o:	$(BONUS_DIR)%.c $(LIBS) Makefile
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				$(RM) $(OBJS)
				$(RM) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(OBJ_DIR)
				$(RM) $(NAME)
				@$(RM) $(BONUS)

re:				fclean $(NAME)

rebonus:		fclean $(BONUS)

info:
				$(info $(SRCS_FILES))
				$(info $(BONUS_FILES))

.PHONY:		all bonus clean fclean re rebonus info
