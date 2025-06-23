/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_var2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:06:05 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2025/06/07 08:49:48 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	remove_node2(t_par *current)
{
	int	i;

	i = 0;
	if (current->infile)
	{
		while (current->infile[i])
			free(current->infile[i++]);
		free(current->infile);
	}
	if (current->outfile)
	{
		i = 0;
		while (current->outfile[i])
			free(current->outfile[i++]);
		free(current->outfile);
	}
	if (current->parameter)
	{
		i = 0;
		while (current->parameter[i])
			free(current->parameter[i++]);
		free(current->parameter);
	}
	if (current->command)
		free(current->command);
}

void	remove_node_var(t_par *current, t_par *next, t_parse *data)
{
	t_par	*prev;

	if (!current || !data)
		return ;
	if (data->head == current)
		data->head = next;
	else
	{
		prev = data->head;
		while (prev && prev->next != current)
			prev = prev->next;
		if (prev)
			prev->next = next;
	}
	remove_node2(current);
	free(current);
}

void	add_command(char *str, t_env *data)
{
	char	*var;
	char	*value;
	int		count;

	count = 0;
	var = create_var(str);
	while (str[count] != '=' && str[count])
		count++;
	value = create_value(str + count + 1);
	add_elem(data, var, value, "var");
	free (var);
	free (value);
}

int	run_command_var(t_env *var, t_parse *data, bool action)
{
	t_par	*current;
	t_par	*next;
	bool	exit;

	if (!var->head)
		return (1);
	current = data->head;
	exit = false;
	if (current && !exit)
	{
		next = current->next;
		if (action && ft_strchr(current->command, '='))
			add_command(current->command, var);
		exit = select_var(current, next, data);
		current = next;
	}
	if (!data->head)
		return (42);
	return (0);
}
