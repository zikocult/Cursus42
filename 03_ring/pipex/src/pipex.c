/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 10:02:35 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/08/16 13:38:27 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	init_pipex(char *argv, char **env, t_pipe *data)
{
	int	i;

	i = 0;
	while (!ft_strnstr(env[i], "PATH=", 5))
		i++;
	data->paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (data->paths[i])
	{
		data->paths[i] = ft_strjoin(data->paths[i], "/");
		i++;
	}
	if (argv)
		data->cmd1 = ft_strdup("patata");
}

int	main(int argc, char **argv, char **env)
{
	t_pipe	data;
	int		i;

	if (argc != 5)
	{ 
		ft_printf("Wrong number of arguments\n");
		ft_printf("Example: ./pipex <file1> <cmd1> <cmd2> <file2>\n");
		exit (1);
	}
	else
	{
		i = 1;

		while (i++ <= 2)
			init_pipex(argv[i], env, &data);
		i = 0;
		while (data.paths[i])
		{
			ft_printf("Path[%i] - %s\n", i, data.paths[i]);
			i++;
		}
	}
}
