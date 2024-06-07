# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbaruls- <gbaruls-@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/07 16:53:47 by gbaruls-          #+#    #+#              #
#    Updated: 2024/06/07 17:03:05 by gbaruls-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_display_file

SRCS 		= ft_display_file.c
OBJS		= ft_display_file.o

CC		= cc
CFLAGS		= -Wall -Werror -Wextra
RM		= rm -rf


all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c Makefile
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re
