/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:18:11 by pamanzan          #+#    #+#             */
/*   Updated: 2025/06/07 16:43:08 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	build_command_args(t_par *current, char **res)
{
	int		i;
	char	*temp;

	i = 0;
	res[0] = ft_strdup(current->command);
	if (current->parameter)
	{
		while (current->parameter[i])
		{
			temp = ft_strtrim(current->parameter[i], " \n");
			res[i + 1] = ft_strdup(temp);
			free(temp);
			i++;
		}
	}
	res[i + 1] = NULL;
}

void	write_heredoc(t_env *data, t_child *params)
{
	if (pipe(params->heredoc_pipe))
		return (perror("Heredoc pipe"));
	if (dup2(params->heredoc_pipe[0], STDIN_FILENO) == -1)
		return (perror("Heredoc dup2"));
	if (write(params->heredoc_pipe[1], data->heredoc_content,
			ft_strlen(data->heredoc_content)) == -1)
		return (perror("Heredoc write"));
	if (close(params->heredoc_pipe[1]))
		return (perror("Heredoc close"));
}

static int	check_built_father(t_par *current, t_child params, t_env *data)
{
	int	ret;

	ret = 0;
	if (!search_doble_inf(current))
		handle_input_heredoc(current, &params, data);
	if (current->command)
	{
		if (!ft_strcmp(current->command, "export"))
			ret = run_export(data, current->parameter);
		else if (!ft_strcmp(current->command, "cd"))
			ret = run_cd(data, current->parameter);
		else if (!ft_strcmp(current->command, "unset"))
			ret = run_unset(data, current->parameter);
		else
			return (0);
		data->exit_var = ret;
		return (1);
	}
	return (0);
}

static void	init_params(t_child *params, t_parse *state)
{
	params->num_pipes = count_pipes(state);
	params->pipes = create_big_pip(params->num_pipes);
	create_pipes(params->pipes, params->num_pipes);
	params->i = 0;
	params->last_fd = -1;
	params->fd = -1;
	params->heredoc_pipe[0] = 0;
	params->heredoc_pipe[1] = 0;
}

void	execute_pipex(t_parse *state, t_env *data)
{
	t_par	*current;
	t_child	params;
	pid_t	pid;

	current = state->head;
	init_params(&params, state);
	while (current)
	{
		if (!check_built_father(current, params, data))
		{
			pid = fork();
			if (pid == -1)
				malloc_error("fork");
			else if (pid == 0)
				handle_child_process(current, params, data);
		}
		if (params.heredoc_pipe[0] > 2)
			close(params.heredoc_pipe[0]);
		free(data->heredoc_content);
		data->heredoc_content = NULL;
		current = current->next;
		params.i++;
	}
	end_execute(params, data);
}
