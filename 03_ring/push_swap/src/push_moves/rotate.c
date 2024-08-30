/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:50:20 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/08/29 11:19:20 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	rotate(t_content **head)
{
	t_content	*new_node;

	if (head == NULL || *head == NULL)
		return ;
	new_node = find_last_node(*head);
	new_node->next = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	new_node->next->prev = new_node;
	new_node->next->next = NULL;
}

void	ra(t_push *data)
{
	rotate(&data->a_head);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_push *data)
{
	rotate(&data->b_head);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_push *data)
{
	rotate(&data->a_head);
	rotate(&data->b_head);
	ft_putstr_fd("rr\n", 1);
}
