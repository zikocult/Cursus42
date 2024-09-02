/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 23:40:10 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/09/03 01:27:53 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	set_position(t_content *head)
{
	int			i;
	int			median;
	t_content	*curr;

	i = 0;
	curr = head;
	if (!head)
		return ;
	median = list_len(head) / 2;
	while (curr)
	{
		curr->position = i;
		if (i + 1 <= median)
			curr->under_median = true;
		else
			curr->under_median = false;
		curr = curr->next;
		i++;
	}
}

static void	set_target(t_content *head_a, t_content *head_b)
{
	t_content	*curr_a;
	t_content	*curr_b;
	t_content	*target;
	long		best_index;

	curr_b = head_b;
	while (curr_b)
	{
		best_index = LONG_MAX;
		curr_a = head_a;
		while (curr_a)
		{
			if (curr_a->value > curr_b->value && curr_a->value < best_index)
			{
				best_index = curr_a->value;
				target = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (LONG_MAX == best_index)
			curr_b->target = find_min(head_a);
		else
			curr_b->target = target;
		curr_b = curr_b->next;
	}
}

void	set_price(t_content *head_a, t_content *head_b)
{
	t_content	*curr;

	curr = head_b;
	while (curr)
	{
		curr->price = curr->position;
		if (!(curr->under_median))
			curr->price = list_len(head_b) - (curr->position);
		if (curr->target->under_median)
			curr->price += curr->target->position;
		else
			curr->price += list_len(head_a) - (curr->target->position);
		if ((curr->under_median == true && curr->target->under_median == false)
			|| (curr->target->under_median == true
				&& curr->under_median == false))
			curr->price += 1;
		curr = curr->next;
	}
}

void	set_best_move(t_content *head)
{
	long		best_value;
	t_content	*best_move;
	t_content	*curr;

	curr = head;
	best_value = LONG_MAX;
	if (!curr)
		return ;
	while (curr)
	{
		if (curr->price < best_value)
		{
			best_value = curr->price;
			best_move = curr;
		}
		curr->best_move = false;
		curr = curr->next;
	}
	best_move->best_move = true;
}

void	init_nodes(t_content *head_a, t_content *head_b)
{
	set_position(head_a);
	set_position(head_b);
	set_target(head_a, head_b);
	set_price(head_a, head_b);
	set_best_move(head_b);
}
