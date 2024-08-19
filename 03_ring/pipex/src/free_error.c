/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 10:30:31 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/08/19 20:04:44 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	error_fork(t_pipe *data)
{
	clean_exit(data);
	exit (1);
}

void	error_args(void)
{
	ft_printf("Wrong number of arguments\n");
	ft_printf("Example: ./pipex <file1> <cmd1> <cmd2> <file2>\n");
	exit (1);
}

void	free_pointer(char **pointer)
{
	int	i;

	i = 0;
	while (pointer[i])
		i++;
	while (i >= 0)
	{
		free(pointer[i]);
		i--;
	}
	free(pointer);
}

void	clean_exit(t_pipe *data)
{
	free_pointer(data->cmd);
	free_pointer(data->param);
	free_pointer(data->paths);
	if (data->infile >= 0)
		close(data->infile);
	if (data->outfile >= 0)
		close(data->outfile);
	free_pointer(data->files);
}
