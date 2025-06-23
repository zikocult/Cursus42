/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redi_infiles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:24:19 by pamanzan          #+#    #+#             */
/*   Updated: 2025/06/07 16:31:09 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	handle_infile(char *src, t_child *params)
{
	char	*str;

	str = ft_strtrim(src, " _");
	params->fd = open(str, O_RDONLY);
	if (params->fd == -1)
	{
		error_msg(str, 3);
		if (str)
			free(str);
		exit(130);
	}
	free(str);
}

int	handle_input_redirection(t_par *current, t_child *params, t_env *data)
{
	int	position;

	position = 0;
	(void)data;
	if (search_doble_inf(current) || params->fd == -1)
	{
		while (current->infile[position])
		{
			if (current->infile[position][0] == '_')
				handle_infile(current->infile[position], params);
			position++;
		}
		close_previous_fd(params);
	}
	redirect_and_close(params->last_fd, STDIN_FILENO);
	return (0);
}
