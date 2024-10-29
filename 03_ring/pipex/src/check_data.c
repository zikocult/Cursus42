/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:15:51 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/10/29 18:09:40 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	check_cmds2(t_pipe *data, int i)
{
	int		j;
	int		control;
	char	*temp;

	j = 0;
	control = 0;
	while (data->paths[j] && control == 0)
	{
		temp = ft_strjoin(data->paths[j], data->cmd[i]);
		if (access(temp, X_OK) != -1)
		{
			free(data->cmd[i]);
			data->cmd[i] = ft_strdup(temp);
			control = 1;
		}
		free(temp);
		j++;
	}
	return (control);
}

void	check_cmds(t_pipe *data, int argc)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (check_cmds2(data, i) == 0)
		{
			ft_putstr_fd("Comando incorrecto\n", 2);
			clean_exit(data);
			exit (1);
		}
		i++;
	}
}
