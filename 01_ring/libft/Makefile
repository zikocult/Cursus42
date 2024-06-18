# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbaruls- <gbaruls-@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/11 11:42:44 by gbaruls-          #+#    #+#              #
#    Updated: 2024/06/18 15:10:41 by gbaruls-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
LIBS		= libft.h

SRCS_FILES	= ft_memset ft_isdigit ft_isalnum ft_isalpha ft_isprint \
			  ft_putendl_fd ft_memcpy ft_calloc ft_split ft_strjoin \
			  ft_strnstr ft_strrchr ft_putstr_fd ft_strncmp ft_strtrim \
			  ft_putnbr_fd ft_toupper ft_strlcat ft_strchr ft_atoi \
			  ft_substr ft_strmapi ft_strlen ft_memchr ft_itoa \
			  ft_putchar_fd ft_memmove ft_strlcpy ft_tolower ft_memcmp\
			  ft_strdup ft_striteri ft_bzero ft_isascii

SRCS 		= $(addsuffix .c, $(SRCS_FILES))
OBJS		= $(addsuffix .o, $(SRCS_FILES))

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RANLIB		= ranlib
RM			= rm -rf
MKDIR		= mkdir -p

all:		$(NAME)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)
			$(RANLIB) $(NAME)

%.o: %.c $(LIBS) Makefile
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

normi:
	@norminette $(SRCS) $(LIBS)

info:
	$(info $(SRCS_FILES))
	$(info $(SRCS))
	$(info $(OBJS))

.PHONY:		all clean fclean re info normi
