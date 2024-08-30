/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:41:53 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/08/29 11:43:55 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	push(t_content **dest, t_content **src)
{
	t_content	*new_node;

	if (*src == NULL)
		return ;
	new_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	new_node->prev = NULL;
	if (*dest == NULL)
	{
		*dest = new_node;
		new_node->next = NULL;
	}
	else
	{
		new_node->next = *dest;
		new_node->next->prev = new_node;
		*dest = new_node;
	}
}

void		pa(t_push *data)
{
	push(&data->a_head, &data->b_head);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_push *data)
{
	push(&data->b_head, &data->a_head);
	ft_putstr_fd("pb\n", 1);
}
