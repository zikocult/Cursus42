/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:59:49 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/09/05 00:36:26 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_content
{
	int					value;
	int					position;
	int					price;
	bool				under_median;
	bool				best_move;
	struct s_content	*target;
	struct s_content	*next;
	struct s_content	*prev;
}	t_content;

typedef struct s_push
{
	int			median;
	char		**input;
	bool		check;
	t_content	*a_head;
	t_content	*b_head;
	t_content	*a_tail;
}	t_push;

//Initialitzation and checks
void		init_data_argv(char *argv, t_push *data, bool check);
void		init_data_argc(int argc, char **argv, t_push *data, bool check);
void		init_list(t_push *data, bool check);
bool		check_alpha(const char *ptr);
void		remove_node(t_content *node, t_push *data);
void		insert_end(t_content **tail, t_content **head, int value,
				t_push *data);
void		init_med(t_push *data);

// Utils and clean
long		ft_atol(const char *ptr);
void		deallocate(t_content **head);
void		free_pointer(char **pointer);
void		printerror(int error, bool check);
void		clean_exit(t_push *data);

// Mandatory commands
void		sa(t_push *data, bool check);
void		sb(t_push *data, bool check);
void		ss(t_push *data, bool check);
void		pa(t_push *data, bool check);
void		pb(t_push *data, bool check);
void		ra(t_push *data, bool check);
void		rb(t_push *data, bool check);
void		rr(t_push *data, bool check);
void		rra(t_push *data, bool check);
void		rrb(t_push *data, bool check);
void		rrr(t_push *data, bool check);

// Turkey sort algorithm
bool		sorted_list(t_content *head);
void		sortofthree(t_content **head, t_push *data);
void		five_elements(t_content **head_a, t_content **head_b, t_push *data);
void		turkey_sort(t_push *data);
void		up_min_a(t_push *data);
void		pusht_to_b(t_push *data, bool check);
void		finish_rotation(t_content **head, t_content *node, char list,
				t_push *data);

// Init stack
void		init_nodes(t_content *head_a, t_content *head_b);
void		set_best_move(t_content *head);
void		set_position(t_content *head);
int			list_len(t_content *head);
t_content	*cheap_node(t_content *head);
t_content	*find_max(t_content *head);
t_content	*find_min(t_content *head);
t_content	*find_last_node(t_content *head);

#endif
