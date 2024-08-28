/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 01:17:49 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/08/28 01:29:27 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_content	*cheap_node(t_content *head)
{
	t_content	*curr;

	curr = head;
	while (curr)
	{
		if (curr->best)
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}

void	five_elements(t_content **head_a, t_content **head_b, t_push *data)
{
	t_content	*small;

	while (list_len(*head_a) > 3)
	{
		small = find_small(*head_a);
		init_nodes(*head_a, *head_b);
		finish_rotation(head_a, small, 'a', data);
		pb(data);
	}
}
