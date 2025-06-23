/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:18:23 by pamanzan          #+#    #+#             */
/*   Updated: 2025/06/05 18:52:46 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	ft_str_isalpha(char *str)
{
	int	upper;
	int	lower;

	while (*str != '\0')
	{
		upper = (*str >= 'A' && *str <= 'Z');
		lower = (*str >= 'a' && *str <= 'z');
		if (!upper && !lower)
			return (0);
		str++;
	}
	return (1);
}

static int	exit_checker(t_parse *state)
{
	t_par	*current;
	int		parameter;

	current = state->head;
	parameter = count_args_double_pointer(current->parameter);
	if (!state || !state->head)
		return (1);
	if (parameter >= 1 && ft_str_isalpha(current->parameter[0]))
	{
		ft_putstr_fd("exit: only numeric arguments\n", 2);
		return (1);
	}
	if (parameter > 1)
	{
		ft_putstr_fd("exit: too many arguments\n", 2);
		return (1);
	}
	return (0);
}

void	run_exit(t_parse *state, t_env *data)
{
	t_par	*current;

	current = state->head;
	if (exit_checker(state))
		return ;
	else
	{
		if (count_args_double_pointer(current->parameter) == 1)
		{
			data->exit_var = ft_atoi(current->parameter[0]);
			rl_clear_history();
			free_parse(state);
			ft_putstr_fd("exit\n", 2);
			exit((unsigned short)data->exit_var);
		}
		else
		{
			rl_clear_history();
			free_parse(state);
			ft_putstr_fd("exit\n", 2);
			exit((unsigned short)data->status);
		}
	}
}
