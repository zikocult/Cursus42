/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:32:18 by Guillem Bar       #+#    #+#             */
/*   Updated: 2025/04/28 16:39:14 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_temp_data(t_parse *data)
{
	if (data->command)
		free(data->command);
	if (data->parameter)
		free(data->parameter);
	if (data->infile)
		free(data->infile);
	if (data->outfile)
		free(data->outfile);
}

void	copy_data(t_par *new_node, t_parse *data)
{
	if (data->command)
		new_node->command = ft_strdup(data->command);
	if (data->parameter)
		new_node->parameter = ft_split(data->parameter, '#');
	if (data->infile)
		new_node->infile = ft_split(data->infile, '#');
	if (data->outfile)
		new_node->outfile = ft_split(data->outfile, '#');
}

void	add_node(t_parse *data)
{
	t_par	*new_node;

	new_node = (t_par *)malloc(sizeof(t_par));
	if (!new_node)
		return ;
	init_newnode(new_node);
	copy_data(new_node, data);
	free_temp_data(data);
	if (!data->head)
	{
		data->head = new_node;
		data->tail = new_node;
	}
	else
	{
		data->tail->next = new_node;
		data->tail = new_node;
	}
	init_data(data, 0);
}
