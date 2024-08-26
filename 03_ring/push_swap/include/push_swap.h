/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:59:49 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/08/26 22:14:41 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include <stdlib.h>

typedef struct s_content
{
	int					value;
	struct s_content	*next;
	struct s_content	*prev;
}	t_content;

typedef struct s_push
{
	char		**input;
	t_content	*a_tail;
	t_content	*a_head;
	t_content	*b_tail;
	t_content	*b_head;
}	t_push;

void		init_data_argv(char *argv, t_push *data);
void		init_data_argc(int argc, char **argv, t_push *data);
void		init_list(t_push *data);

void		first_node(t_content **tail, t_content **head, int value,
				t_push *data);
void		insert_end(t_content **tail, t_content **head, int value,
				t_push *data);
void		insert_begin(t_content **tail, t_content **head, int value,
				t_push *data);
t_content	*find_node(t_content *tail, int value);
void		remove_node(t_content *node);

void		deallocate(t_content **tail, t_content **head);
void		free_pointer(char **pointer);
void		printerror(int error);
void		clean_exit(t_push *data);

#endif
