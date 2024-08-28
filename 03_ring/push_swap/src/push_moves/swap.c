/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:09:57 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/08/27 19:34:53 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	swap(t_content **head)
{
	if (*head == NULL || head == NULL)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_push *data)
{
	swap(&data->a_head);
	ft_printf("sa\n");
}

void	sb(t_push *data)
{
	swap(&data->b_head);
	ft_printf("sb\n");
}

void	ss(t_push *data)
{
	swap(&data->a_head);
	swap(&data->b_head);
	ft_printf("ss\n");
}
