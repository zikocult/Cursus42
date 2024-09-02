/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tinysorts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:20:21 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/08/30 11:45:37 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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
		ra(data, true);
	else if ((*head)->next == high_node)
		rra(data, true);
	if ((*head)->value > (*head)->next->value)
		sa(data, true);
}

void	five_elements(t_content **head_a, t_content **head_b, t_push *data)
{
	t_content	*small;

	while (list_len(*head_a) > 3)
	{
		small = find_min(*head_a);
		init_nodes(*head_a, *head_b);
		finish_rotation(head_a, small, 'a', data);
		pb(data, true);
	}
}
