/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 01:17:49 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/08/30 11:35:51 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_content	*cheap_node(t_content *head)
{
	t_content	*curr;

	curr = head;
	while (curr)
	{
		if (curr->best_move)
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}

bool	sorted_list(t_content *head)
{
	t_content	*curr;

	if (!head)
		return (true);
	curr = head;
	while (curr->next)
	{
		if (curr->value > curr->next->value)
			return (false);
		curr = curr->next;
	}
	return (true);
}

void	up_min_a(t_push *data)
{
	t_content	*min;

	min = find_min(data->a_head);
	if (min->under_median)
		while (data->a_head != min)
			ra(data, true);
	else
		while (data->a_head != min)
			rra(data, true);
}

t_content	*find_max(t_content *head)
{
	long		max;
	t_content	*max_node;
	t_content	*curr;

	curr = head;
	max = LONG_MIN;
	if (!curr)
		return (NULL);
	while (curr)
	{
		if (curr->value > max)
		{
			max = curr->value;
			max_node = curr;
		}
		curr = curr->next;
	}
	return (max_node);
}

t_content	*find_min(t_content *head)
{
	long		min;
	t_content	*min_node;
	t_content	*curr;

	curr = head;
	min = LONG_MAX;
	if (!curr)
		return (NULL);
	while (curr)
	{
		if (curr->value < min)
		{
			min = curr->value;
			min_node = curr;
		}
		curr = curr->next;
	}
	return (min_node);
}
