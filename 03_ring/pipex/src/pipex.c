/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 10:02:35 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/08/19 20:22:40 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	parent(t_pipe *data, int *fd, char **env)
{
	char	**param;

	param = ft_split(data->param[1], ' ');
	if (!param)
		clean_exit(data);
	data->outfile = open(data->files[1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (data->outfile < 0)
	{
		clean_exit(data);
		ft_printf("outfile error\n");
		exit(1);
	}
	dup2(data->outfile, 1);
	dup2(fd[0], 0);
	close(fd[0]);
	close(fd[1]);
	execve(data->cmd[1], param, env);
	free_pointer(param);
}

void	child(t_pipe *data, int *fd, char **env)
{
	char	**param;

	param = ft_split(data->param[0], ' ');
	if (!param)
		clean_exit(data);
	data->infile = open(data->files[0], O_RDONLY);
	if (data->infile < 0)
	{
		clean_exit(data);
		ft_printf("Infile error\n");
		exit (1);
	}
	dup2(data->infile, 0);
	dup2(fd[1], 1);
	close(fd[0]);
	close(fd[1]);
	execve(data->cmd[0], param, env);
	free_pointer(param);
}

int	main(int argc, char **argv, char **env)
{
	t_pipe	data;
	int		fd[2];

	if (argc == 5 && argv)
	{
		init_path(env, &data);
		init_cmd(argc - 2, argv, &data);
		init_files(argc, argv, &data);
		check_cmds(&data, argc - 3);
		if (pipe(fd) == -1)
			error_fork(&data);
		data.pid = fork();
		if (data.pid == -1)
			error_fork(&data);
		if (data.pid == 0)
			child(&data, fd, env);
		waitpid(data.pid, NULL, 0);
		parent(&data, fd, env);
		close (fd[0]);
		close (fd[1]);
		clean_exit(&data);
	}
	else
		error_args();
	return (0);
}
	// ft_printf("%s\n", data.cmd[0]);
	// ft_printf("%s\n", data.cmd[1]);
	// ft_printf("%s\n", data.param[0]);
	// ft_printf("%s\n", data.param[1]);
	// ft_printf("%s\n", data.files[0]);
	// ft_printf("%s\n", data.files[1]);
	// ft_printf("%i\n", data.infile);
	// ft_printf("%i\n", data.outfile);
