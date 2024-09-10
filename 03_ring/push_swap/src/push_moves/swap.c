/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:09:57 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/09/10 13:07:03 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	swap(t_content **head)
{
	if (head == NULL || *head == NULL || list_len(*head) <= 1)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_push *data, bool check)
{
	swap(&data->a_head);
	if (check)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_push *data, bool check)
{
	swap(&data->b_head);
	if (check)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_push *data, bool check)
{
	swap(&data->a_head);
	swap(&data->b_head);
	if (check)
		ft_putstr_fd("ss\n", 1);
}
