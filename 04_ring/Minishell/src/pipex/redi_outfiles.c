/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redi_outfiles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:29:52 by pamanzan          #+#    #+#             */
/*   Updated: 2025/06/07 16:41:25 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	end_output_one(t_child *params, t_par *current)
{
	redirect_and_close(params->last_fd, STDOUT_FILENO);
	if (!search_doble_inf(current))
		return (1);
	else
		exit(EXIT_SUCCESS);
}

static int	handle_output_one(t_par *current, t_child *params)
{
	char	*str;

	while (current->outfile[params->position])
	{
		str = new_file_name(current->outfile[params->position]);
		params->fd = open(str, O_WRONLY | O_CREAT | O_TRUNC, FILE_MODE);
		if (params->fd == -1)
		{
			if (errno == EACCES)
				error_msg(str, 2);
			else
				error_msg(str, 3);
			free(str);
			if (!search_doble_inf(current))
				return (1);
			else
				exit(EXIT_FAILURE);
		}
		free(str);
		close_previous_fd(params);
		params->position++;
	}
	return (end_output_one(params, current));
}

static int	handle_output_two(t_par *current, t_child *params)
{
	char	*str;

	str = new_file_name(current->outfile[params->position]);
	if (current->outfile[params->position]
		&& current->outfile[params->position][0] == '>')
		params->fd = open(str, O_WRONLY | O_CREAT | O_APPEND, FILE_MODE);
	else
		params->fd = open(str, O_WRONLY | O_CREAT | O_TRUNC, FILE_MODE);
	if (params->fd == -1)
	{
		if (errno == EACCES)
			error_msg(str, 2);
		else
			error_msg(str, 3);
		free(str);
		if (!search_doble_inf(current))
			return (1);
		else
			exit(EXIT_FAILURE);
	}
	free(str);
	close_previous_fd(params);
	params->position++;
	return (0);
}

int	handle_output_redirection(t_par *current, t_child *params)
{
	params->position = 0;
	params->last_fd = -1;
	while (current->outfile && current->outfile[params->position])
	{
		if (!current->command)
			handle_output_one(current, params);
		else
			handle_output_two(current, params);
	}
	if (current->outfile && current->outfile[params->position]
		&& !search_doble_inf(current))
	{
		if (!current->command)
			handle_output_one(current, params);
		else
			handle_output_two(current, params);
		return (1);
	}
	else
		redirect_and_close(params->last_fd, STDOUT_FILENO);
	return (0);
}
