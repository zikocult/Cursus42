# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbarulls <gbarulls@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 18:02:47 by gbarulls          #+#    #+#              #
#    Updated: 2023/02/02 22:40:20 by gbarulls         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


OBJ_DIR		=	./obj

SRCS		=	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
				ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
				ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c \
				ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c \
				ft_toupper.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
				ft_strtrim.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c\
				ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c

OBJS		= $(SRCS:.c=.o)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I.
AR			= ar rcs
RM			= rm -f
NAME		= libft.a
INCLUDE = libft.h

%.o: %.c ${INCLUDE} Makefile
			${CC} ${CFLAGS} -c $< -o $@

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re
