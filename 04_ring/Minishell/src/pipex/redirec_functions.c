/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirec_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:16:12 by pamanzan          #+#    #+#             */
/*   Updated: 2025/06/06 19:13:37 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	close_previous_fd(t_child *params)
{
	if (params->last_fd > 2)
		close(params->last_fd);
	params->last_fd = params->fd;
}

void	redirect_and_close(int fd, int std_fd)
{
	if (fd != -1)
	{
		dup2(fd, std_fd);
		close(fd);
	}
}

int	return_open(t_par *current)
{
	int		i;
	char	*str;
	int		quant;

	i = 0;
	while (current->infile[i])
	{
		if (current->infile[i][0] == '_')
		{
			str = ft_strtrim(current->infile[i], " _");
			quant = open(str, O_RDONLY);
			if (quant == -1)
			{
				free(str);
				return (quant);
			}
			free(str);
		}
		i++;
		quant = 42;
	}
	return (quant);
}

int	search_doble_inf(t_par *current)
{
	int	i;

	i = 0;
	while (current->infile && current->infile[i])
	{
		if (ft_strchr(current->infile[i], '<'))
			return (0);
		i++;
	}
	return (1);
}

char	*search_file(t_par *current)
{
	int		i;
	char	*str;

	i = 0;
	while (current->infile && current->infile[i])
	{
		if (ft_strchr(current->infile[i], '_'))
		{
			str = ft_strtrim(current->infile[i], " _");
			if (access(str, F_OK != 0))
			{
				if (str)
					free(str);
				return (current->infile[i]);
			}
			free(str);
		}
		i++;
	}
	return (NULL);
}
