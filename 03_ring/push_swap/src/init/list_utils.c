/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:24:50 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/09/05 00:54:11 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	list_len(t_content *head)
{
	int			count;
	t_content	*curr;

	if (!head)
		return (0);
	curr = head;
	count = 0;
	while (curr)
	{
		count++;
		curr = curr->next;
	}
	return (count);
}

t_content	*find_last_node(t_content *head)
{
	if (NULL == head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

static void	first_node(t_content **head, t_content **tail, int value,
				t_push *data)
{
	t_content	*new_node;

	new_node = malloc(sizeof(t_content));
	if (!new_node)
	{
		clean_exit(data);
		printerror(2, true);
	}
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	*head = new_node;
	*tail = new_node;
}

void	insert_end(t_content **head, t_content **tail, int value, t_push *data)
{
	t_content	*new_node;

	if (*head == NULL)
	{
		first_node(head, tail, value, data);
		return ;
	}
	new_node = malloc(sizeof(t_content));
	if (!new_node)
	{
		clean_exit(data);
		printerror(2, true);
	}
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = *tail;
	(*tail)->next = new_node;
	*tail = new_node;
}
