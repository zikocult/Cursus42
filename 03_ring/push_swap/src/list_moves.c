/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:24:50 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/08/26 22:20:41 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_content	*find_node(t_content *tail, int value)
{
	t_content	*curr;

	curr = tail;
	while (curr)
	{
		if (curr->value == value)
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}

void	remove_node(t_content *node)
{
	if (node->prev != NULL)
		node->prev->next = node->next;
	if (node->next != NULL)
		node->next->prev = node->prev;
	free(node);
}

void	insert_begin(t_content **tail, t_content **head, int value,
			t_push *data)
{
	t_content	*new_node;

	if (*head == NULL)
	{
		first_node(tail, head, value, data);
		return ;
	}
	new_node = malloc(sizeof(t_content));
	if (!new_node)
	{
		clean_exit(data);
		printerror(2);
	}
	new_node->value = value;
	new_node->next = *tail;
	new_node->prev = NULL;
	(*tail)->prev = new_node;
	*tail = new_node;
}

void	insert_end(t_content **tail, t_content **head, int value, t_push *data)
{
	t_content	*new_node;

	if (*head == NULL)
	{
		first_node(tail, head, value, data);
		return ;
	}
	new_node = malloc(sizeof(t_content));
	if (!new_node)
	{
		clean_exit(data);
		printerror(2);
	}
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = *head;
	(*head)->next = new_node;
	*head = new_node;
}

void	first_node(t_content **tail, t_content **head, int value, t_push *data)
{
	t_content	*new_node;

	new_node = malloc(sizeof(t_content));
	if (!new_node)
	{
		clean_exit(data);
		printerror(2);
	}
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	*tail = new_node;
	*head = new_node;
}
