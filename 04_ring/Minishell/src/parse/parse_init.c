/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:26:46 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2025/04/08 23:41:11 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	init_newnode(t_par *new_node)
{
	new_node->command = NULL;
	new_node->parameter = NULL;
	new_node->infile = NULL;
	new_node->outfile = NULL;
	new_node->next = NULL;
}

void	init_data(t_parse *data, bool mode)
{
	if (mode)
	{
		data->head = NULL;
		data->tail = NULL;
	}
	data->command = NULL;
	data->parameter = NULL;
	data->infile = NULL;
	data->outfile = NULL;
	data->in_single_quotes = 0;
	data->in_double_quotes = 0;
}

void	free_pointer(char **pointer)
{
	int	i;

	i = 0;
	while (pointer[i])
		i++;
	while (i >= 0)
	{
		free(pointer[i]);
		i--;
	}
	free(pointer);
}

void	free_parse(t_parse *data)
{
	t_par	*current;
	t_par	*next;

	current = data->head;
	while (current)
	{
		next = current->next;
		if (current->command)
			free(current->command);
		if (current->parameter)
			free_pointer(current->parameter);
		if (current->infile)
			free_pointer(current->infile);
		if (current->outfile)
			free_pointer(current->outfile);
		free(current);
		current = next;
	}
	data->head = NULL;
	data->tail = NULL;
}
