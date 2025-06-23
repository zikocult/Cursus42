/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 11:13:11 by pamanzan          #+#    #+#             */
/*   Updated: 2025/04/22 17:09:35 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_pipes(int **pipes, int num_pipes)
{
	int	i;

	i = 0;
	while (i < num_pipes)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		free(pipes[i]);
		i++;
	}
	free(pipes);
}

void	free_memory(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	ptr = NULL;
}

void	free_list(t_env	*data)
{
	t_var	*current;
	t_var	*next_node;

	current = data->head;
	while (current->next)
	{
		next_node = current->next;
		if (current->content)
			free(current->content);
		if (current->var_name)
			free(current->var_name);
		if (current->type)
			free(current->type);
		if (current)
			free(current);
		current = next_node;
	}
	free(data->tail);
	data->head = NULL;
	data->tail = NULL;
}

void	free_array(char **array, int size)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (i < size && array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
