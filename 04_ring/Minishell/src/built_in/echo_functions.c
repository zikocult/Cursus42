/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:23:37 by pamanzan          #+#    #+#             */
/*   Updated: 2025/06/03 17:03:57 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	look_for_n(char *str)
{
	int	j;

	j = 1;
	while (str[j])
	{
		if (str[j] != 'n')
			return (false);
		j++;
	}
	return (true);
}

int	run_echo(char **args)
{
	int		i;
	bool	minusn;

	i = 0;
	minusn = false;
	if (!args)
		return (0);
	while (args[i][0] == '-')
	{
		minusn = look_for_n(args[i]);
		if (minusn)
			i++;
		else
			break ;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		if (args[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (!minusn)
		ft_putchar_fd('\n', 1);
	return (0);
}
