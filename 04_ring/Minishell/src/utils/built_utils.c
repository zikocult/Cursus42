/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 08:05:08 by pamanzan          #+#    #+#             */
/*   Updated: 2025/06/04 16:13:06 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_built(t_child params, t_par *current, t_env *data)
{
	(void)params;
	if (!ft_strcmp(current->command, "echo"))
		return (run_echo(current->parameter), 1);
	else if (!ft_strcmp(current->command, "pwd"))
		return (run_pwd(), 1);
	else if (!ft_strcmp(current->command, "env"))
		return (run_env(data, current->parameter), 1);
	else if (!ft_strcmp(current->command, "patata"))
		return (printf("CHACHI PIRULIIIIIII!!!!!! 👾👾👾👾👾👾👾👾\n"), 1);
	return (0);
}
