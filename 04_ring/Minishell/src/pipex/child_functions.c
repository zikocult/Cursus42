/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:14:16 by pamanzan          #+#    #+#             */
/*   Updated: 2025/06/07 16:30:05 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*new_file_name(char *str)
{
	char	*temp;
	char	*new_str;
	char	*trimmed_str;
	int		i;

	if (!str)
		return (NULL);
	temp = ft_strdup(str);
	if (!temp)
		return (NULL);
	new_str = (char *)ft_calloc(ft_strlen(temp) + 1, sizeof(char));
	if (!new_str)
		return (free(temp), NULL);
	i = 1;
	while (temp[i])
	{
		new_str[i - 1] = temp[i];
		i++;
	}
	free(temp);
	trimmed_str = ft_strtrim(new_str, " \n");
	return (free(new_str), trimmed_str);
}

void	redirect_io(t_par *current, t_child params, t_env *data)
{
	if (current->infile)
		handle_input_redirection(current, &params, data);
	else if (params.i > 0)
	{
		if (dup2(params.pipes[params.i - 1][READ_END], STDIN_FILENO) == -1)
			malloc_error("dup2 stdin");
	}
	if (current->outfile)
		handle_output_redirection(current, &params);
	else if (params.i < params.num_pipes)
	{
		if (dup2(params.pipes[params.i][WRITE_END], STDOUT_FILENO) == -1)
			malloc_error("dup2 stdout");
	}
}

static void	end_child_process(t_child params, t_env *data, char **res)
{
	if (params.heredoc_pipe[0] > 2)
		close(params.heredoc_pipe[0]);
	free(data->heredoc_content);
	free_pipes(params.pipes, params.num_pipes);
	free_memory(res);
	exit(data->exit_var);
}

void	handle_child_process(t_par *current, t_child params, t_env *data)
{
	char	*path;
	char	**res;
	char	**env_vars;
	int		count;

	count = count_args_double_pointer(current->parameter);
	res = ft_calloc(sizeof(char *), count + 2);
	if (!res)
		exit(EXIT_FAILURE);
	redirect_io(current, params, data);
	close_pipes(params.pipes, params.num_pipes);
	if (data->heredoc_content)
		write_heredoc(data, &params);
	if (!check_built(params, current, data))
	{
		path = check_path(current, data);
		build_command_args(current, res);
		env_vars = enviroment(data);
		if (path)
			execve(path, res, env_vars);
	}
	end_child_process(params, data, res);
}
