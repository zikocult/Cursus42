# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbarulls <gbarulls@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 18:02:47 by gbarulls          #+#    #+#              #
#    Updated: 2025/06/06 16:52:08 by pamanzan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
LIBS		= include/libft.h include/ft_printf.h include/get_next_line.h

SRC_DIR		=	src/
OBJ_DIR		=	obj/

SRCS_FILES	=	src/printf/ft_strings src/printf/ft_number src/printf/ft_pointer \
				src/printf/ft_printf src/bonus/ft_lstmap_bonus src/bonus/ft_lstlast_bonus \
				src/bonus/ft_lstnew_bonus src/bonus/ft_lstadd_front_bonus \
				src/bonus/ft_lstsize_bonus src/bonus/ft_lstclear_bonus \
				src/bonus/ft_lstadd_back_bonus src/bonus/ft_lstdelone_bonus \
				src/bonus/ft_lstiter_bonus src/gnl/get_next_line_utils \
				src/gnl/get_next_line src/original/ft_strchr src/original/ft_strdup \
				src/original/ft_strnstr src/original/ft_tolower src/original/ft_substr \
				src/original/ft_strlen src/original/ft_memset src/original/ft_putstr_fd \
				src/original/ft_putnbr_fd src/original/ft_putendl_fd \
				src/original/ft_strmapi src/original/ft_memmove src/original/ft_memcpy \
				src/original/ft_atoi src/original/ft_strtrim src/original/ft_strncmp \
				src/original/ft_strlcat src/original/ft_strlcpy src/original/ft_split \
				src/original/ft_itoa src/original/ft_isdigit src/original/ft_calloc \
				src/original/ft_strjoin src/original/ft_bzero src/original/ft_memcmp \
				src/original/ft_striteri src/original/ft_isalnum src/original/ft_putchar_fd \
				src/original/ft_isprint src/original/ft_isalpha src/original/ft_isascii \
				src/original/ft_memchr src/original/ft_toupper src/original/ft_strrchr \
				src/original/ft_strcmp src/original/ft_strcpy\
				src/extra/ft_uitoa src/extra/ft_str_rm_str src/extra/ft_num_len

SRCS 		= $(addsuffix .c, $(SRCS_FILES))
SRCDIRS		= $(shell find src/ -type d)
OBJSDIRS	= $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SRCDIRS))
OBJSTEMP	= $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SRCS_FILES))
OBJS		= $(addsuffix .o, $(OBJSTEMP))

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -Iinclude/ -g
AR			= ar rcs
RANLIB		= ranlib
RM			= rm -rf
MKDIR		= mkdir -p

.PHONY:		all clean fclean re info normi home

all:		$(NAME)

$(NAME):	$(OBJSDIRS) $(OBJS)
			$(AR) $(NAME) $(OBJS)
			$(RANLIB) $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(LIBS) Makefile
			$(CC) $(CFLAGS) -c $< -o $@

$(OBJSDIRS) :
	$(MKDIR) $@

clean:
			$(RM) $(OBJS)

fclean:		
			$(RM) $(OBJSDIRS)
			$(RM) $(NAME)

re:			fclean $(NAME)

normi:
	@norminette $(SRCS)
	@norminette $(LIBS)

info:
	$(info $(SRCS_FILES))
