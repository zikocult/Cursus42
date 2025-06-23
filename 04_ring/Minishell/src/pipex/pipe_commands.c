/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:09:11 by pamanzan          #+#    #+#             */
/*   Updated: 2025/06/06 20:16:37 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	create_pipes(int **pipes, int num_pipes)
{
	int	i;

	i = 0;
	while (i < num_pipes)
	{
		if (pipe(pipes[i]) == -1)
		{
			perror("pipe");
			while (i > 0)
			{
				close(pipes[--i][0]);
				close(pipes[i][1]);
			}
			free_pipes(pipes, num_pipes);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	close_pipes(int **pipes, int num_pipes)
{
	int	i;

	i = 0;
	while (i < num_pipes)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
}

void	close_parent_pipes(int i, int num_pipes, int **pipes)
{
	if (i > 0)
		close(pipes[i - 1][READ_END]);
	if (i < num_pipes)
		close(pipes[i][WRITE_END]);
}

void	end_execute(t_child params, t_env *data)
{
	int		status;
	int		process_count;

	(void) data;
	close_pipes(params.pipes, params.num_pipes);
	process_count = params.i;
	while (process_count--)
	{
		wait(&status);
	}
	if (WIFEXITED(status))
		data->exit_var = WEXITSTATUS(status);
	free_pipes(params.pipes, params.num_pipes);
}
