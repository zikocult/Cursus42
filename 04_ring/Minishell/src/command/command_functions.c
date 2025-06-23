/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:07:30 by patri             #+#    #+#             */
/*   Updated: 2025/05/10 15:17:23 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	try_processes(t_parse *parse_data, t_env *data)
{
	if (process_data(parse_data, data, expand_mult))
		return (1);
	if (process_data(parse_data, data, handle_dollar))
		return (1);
	if (process_data(parse_data, data, double_simple_dollar))
		return (1);
	if (process_data(parse_data, data, simple_double_dollar))
		return (1);
	if (process_data(parse_data, data, double_quotes_dollar))
		return (1);
	if (process_data(parse_data, data, single_quotes))
		return (1);
	else
		return (0);
}

void	start_expansion(t_parse *parse_data, t_env *data)
{
	t_par	*current;

	current = parse_data->head;
	while (current)
	{
		if (try_processes(parse_data, data))
		{
			if (count_pipes(parse_data) == 0)
				execute_pipex(parse_data, data);
			current = current->next;
			continue ;
		}
		if (count_pipes(parse_data) == 0)
			execute_pipex(parse_data, data);
		current = current->next;
	}
	if (count_pipes(parse_data) != 0)
		execute_pipex(parse_data, data);
}
