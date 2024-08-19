/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 10:28:28 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/08/19 13:01:26 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	init_files(int argc, char **argv, t_pipe *data)
{
	data->files = (char **)ft_calloc(3, sizeof(char *));
	if (!data->files)
		exit (1);
	data->files[0] = ft_strdup(argv[1]);
	data->files[1] = ft_strdup(argv[argc - 1]);
	data->infile = -1;
	data->outfile = -1;
}

void	fill_data2(t_pipe *data, int pos, char *argv, int i)
{
	int	j;
	int	k;

	j = i;
	while (argv[i])
		i++;
	if (i == j)
	{
		data->param[pos] = (char *)ft_calloc(1, sizeof(char *));
		return ;
	}
	data->param[pos] = (char *)ft_calloc(i - j + 1, sizeof(char *));
	if (!data->param[pos])
		exit (1);
	k = 0;
	while (argv[j])
	{
		data->param[pos][k] = argv[j];
		k++;
		j++;
	}
}

void	fill_data(t_pipe *data, int pos, char *argv)
{
	int	i;
	int	j;

	i = 0;
	while ((argv[i] != ' ' || (argv[i] >= 9 && argv[i] <= 13)) && argv[i])
		i++;
	data->cmd[pos] = (char *)ft_calloc(i + 1, sizeof(char *));
	if (!data->cmd[pos])
		exit (1);
	j = 0;
	while (j < i)
	{
		data->cmd[pos][j] = argv[j];
		j++;
	}
	while ((argv[i] == ' ' && (argv[i] <= 9 || argv[i] >= 13)) && argv[i])
		i++;
	fill_data2(data, pos, argv, i);
}

void	init_cmd(int argc, char **argv, t_pipe *data)
{
	int	i;

	data->cmd = (char **)ft_calloc(argc, sizeof(char *));
	if (!data->cmd)
		exit (1);
	data->param = (char **)ft_calloc(argc, sizeof(char *));
	if (!data->param)
		exit (1);
	i = 0;
	while (i < argc - 1)
	{
		fill_data(data, i, argv[i + 2]);
		i++;
	}
}

void	init_path(char **env, t_pipe *data)
{
	int		i;
	char	**temp_paths;

	i = 0;
	while (!ft_strnstr(env[i], "PATH=", 5))
		i++;
	temp_paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (temp_paths[i])
		i++;
	data->paths = (char **)ft_calloc(i + 1, sizeof(char *));
	if (!data->paths)
		exit(1);
	i = 0;
	while (temp_paths[i])
	{
		data->paths[i] = ft_strjoin(temp_paths[i], "/");
		free(temp_paths[i]);
		i++;
	}
	free(temp_paths);
}
