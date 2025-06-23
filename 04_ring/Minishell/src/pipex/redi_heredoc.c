/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redi_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 07:44:45 by pamanzan          #+#    #+#             */
/*   Updated: 2025/06/23 18:23:01 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	read_input(t_par *current, int position, t_env *data)
{
	char	*str;

	if (current->infile[position][0] == '<')
	{
		str = ft_strtrim(current->infile[position], " <");
		process_heredoc(str, data);
		free(str);
	}
}

static int	handle_file(char *src, t_child *params)
{
	char	*str;

	str = ft_strtrim(src, " _");
	params->fd = open(str, O_RDONLY);
	if (params->fd == -1)
	{
		if (str)
			free(str);
		return (1);
	}
	free(str);
	return (0);
}

static int	last_position_heredoc(t_par *current, char *src, t_child *params)
{
	char	*file;

	file = search_file(current);
	if (src[0] == '_')
	{
		if (handle_file(src, params))
			return (1);
	}
	else
	{
		if (file)
		{
			if (handle_file(src, params))
				return (1);
		}
	}
	return (0);
}

int	handle_input_heredoc(t_par *current, t_child *params, t_env *data)
{
	int		position;
	char	*file;

	file = search_file(current);
	if (!file)
		return (0);
	position = 0;
	while (current->infile[position] && data->exit_var != 130)
	{
		read_input(current, position, data);
		if (current->infile[position + 1] == NULL)
		{
			if (last_position_heredoc(current, current->infile[position],
					params))
				return (1);
		}
		position++;
	}
	return (0);
}
