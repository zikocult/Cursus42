/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 10:50:30 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2025/06/07 10:33:04 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static bool	look_for_commands(t_par *data)
{
	int	i;

	if (!data->command)
		return (false);
	if (!ft_strchr(data->command, '='))
		return (false);
	while (data)
	{
		i = 0;
		if (data->parameter)
		{
			while (data->parameter[i])
			{
				if (!ft_strchr(data->parameter[i], '='))
					return (false);
				i++;
			}
		}
		data = data->next;
	}
	return (true);
}

static bool	look_for_pipes(t_par *data)
{
	int	count;

	count = 0;
	while (data)
	{
		data = data->next;
		count++;
	}
	if (count == 1)
		return (true);
	else
		return (false);
}

static void	moving_elements(t_par *current)
{
	int		i;
	char	*old_command;

	old_command = current->command;
	current->command = current->parameter[0];
	i = 0;
	while (current->parameter[i])
	{
		current->parameter[i] = current->parameter[i + 1];
		i++;
	}
	if (old_command != current->command)
		free(old_command);
}

bool	select_var(t_par *current, t_par *next, t_parse *data)
{
	if (ft_strchr(current->command, '='))
	{
		if (current->parameter && current->parameter[0])
			moving_elements(current);
		else
			remove_node_var(current, next, data);
	}
	else
		return (true);
	return (false);
}

int	command_var(t_env *var, t_parse *data)
{
	int		ret;
	bool	action;

	action = false;
	if (look_for_pipes(data->head) && look_for_commands(data->head))
		action = true;
	ret = 0;
	if (data->head)
	{
		if (ft_strchr(data->head->command, '='))
		{
			while (ret != 42)
			{
				ret = run_command_var(var, data, action);
				if (!data->head)
					break ;
				if (!ft_strchr(data->head->command, '='))
					break ;
			}
		}
	}
	return (ret);
}
