/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   body_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:28:01 by patri             #+#    #+#             */
/*   Updated: 2025/06/07 17:25:29 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	select_type(char *command_buff, t_env *data)
{
	t_parse	state;

	state.head = NULL;
	state.tail = NULL;
	init_data(&state, 1);
	if (!validate_cmdbuff(command_buff))
	{
		data->exit_var = 2;
		return (0);
	}
	parse_token(command_buff, &state);
	if (!state.head->command)
		start_expansion(&state, data);
	else if (!ft_strcmp(&state.head->command[0], "exit"))
		run_exit(&state, data);
	else
		start_expansion(&state, data);
	free_parse(&state);
	return (0);
}
