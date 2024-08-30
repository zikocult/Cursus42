/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:59:49 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/08/29 11:41:22 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_content
{
	int					value;
	int					position;
	int					price;
	bool				under_median;
	bool				best;
	struct s_content	*target;
	struct s_content	*next;
	struct s_content	*prev;
}	t_content;

typedef struct s_push
{
	char		**input;
	t_content	*a_head;
	t_content	*b_head;
	t_content	*a_tail;
}	t_push;

//Recordar borrar el test
void		test(t_push *data, int argc);
void		mostrar_lista(t_push *data);
void		muestra_struct(t_content *head);

//Initialitzation and checks
void		init_data_argv(char *argv, t_push *data);
void		init_data_argc(int argc, char **argv, t_push *data);
void		init_list(t_push *data);
bool		check_alpha(const char *ptr);
void		remove_node(t_content *node, t_push *data);
void		insert_end(t_content **tail, t_content **head, int value,
				t_push *data);

// Mandatory commands
void		sa(t_push *data);
void		sb(t_push *data);
void		ss(t_push *data);
void		pa(t_push *data);
void		pb(t_push *data);
void		ra(t_push *data);
void		rb(t_push *data);
void		rr(t_push *data);
void		rra(t_push *data);
void		rrb(t_push *data);
void		rrr(t_push *data);

// Sort algorithms
bool		sorted_list(t_content *head);
void		sortofthree(t_content **head, t_push *data);
void		five_elements(t_content **head_a, t_content **head_b, t_push *data);
void		push_swap(t_push *data);
void		finish_rotation(t_content **head, t_content *node, char list, t_push *data);

// Init stack
void		init_nodes(t_content *head_a, t_content *head_b);
void		set_best(t_content *head);
void		set_position(t_content *head);
int			list_len(t_content *head);
t_content	*cheap_node(t_content *head);
t_content	*find_small (t_content *head);
t_content	*find_last_node(t_content *head);

// Utils and clean
long		ft_atol(const char *ptr);
void		deallocate(t_content **head);
void		free_pointer(char **pointer);
void		printerror(int error);
void		clean_exit(t_push *data);

#endif
