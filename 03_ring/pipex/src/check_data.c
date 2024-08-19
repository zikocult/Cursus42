/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:15:51 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/08/19 13:07:37 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include <fcntl.h>
#include <unistd.h>

void	check_files(t_pipe *data)
{
	data->infile = open(data->files[0], O_RDONLY);
	if (data->infile < 0)
	{
		clean_exit(data);
		ft_printf("Infile error\n");
		exit (1);
	}
	data->outfile = open(data->files[1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (data->outfile < 0)
	{
		clean_exit(data);
		ft_printf("outfile error\n");
		exit(1);
	}
}

int	check_cmds2(t_pipe *data, int i)
{
	int		j;
	int		control;
	char	*temp;

	j = 0;
	control = 0;
	while (data->paths[j])
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
			ft_printf("Comando incorrecto\n");
			clean_exit(data);
			exit (1);
		}
		i++;
	}
}
