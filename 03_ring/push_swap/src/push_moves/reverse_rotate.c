/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 11:01:19 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/08/29 11:18:46 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	reverse_rotate(t_content **head)
{
	t_content	*new_node;

	if (head == NULL || *head == NULL)
		return ;
	new_node = find_last_node(*head);
	new_node->prev->next = NULL;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
	new_node->next->prev = new_node;
}

void	rra(t_push *data)
{
	reverse_rotate(&data->a_head);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_push *data)
{
	reverse_rotate(&data->b_head);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_push *data)
{
	reverse_rotate(&data->a_head);
	reverse_rotate(&data->b_head);
	ft_putstr_fd("rrr\n", 1);
}
