/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortofthree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:20:21 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/08/28 15:14:58 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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

t_content	*find_small (t_content *head)
{
	long		small;
	t_content	*small_node;
	t_content	*curr;

	curr = head;
	small = LONG_MAX;
	if (!curr)
		return (NULL);
	while (curr)
	{
		if (curr->value < small)
		{
			small = curr->value;
			small_node = curr;
		}
		curr = curr->next;
	}
	return (small_node);
}

void	sortofthree(t_content **head, t_push *data)
{
	int			high;
	t_content	*high_node;
	t_content	*curr;

	curr = *head;
	high = INT_MIN;
	while (curr)
	{
		if (curr->value > high)
		{
			high = curr->value;
			high_node = curr;
		}
		curr = curr->next;
	}
	if (*head == high_node)
		ra(data);
	else if ((*head)->next == high_node)
		rra(data);
	if ((*head)->value > (*head)->next->value)
		sa(data);
}
