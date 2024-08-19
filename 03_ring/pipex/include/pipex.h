/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 09:38:34 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/08/19 20:05:47 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/include/ft_printf.h"
# include "../libft/include/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>

typedef struct s_pipe
{
	char	**cmd;
	char	**param;
	char	**paths;
	char	**files;
	int		infile;
	int		outfile;
	pid_t	pid;
}	t_pipe;

void	init_pipex(char *argv, char **env, t_pipe *data);
void	init_path(char **env, t_pipe *data);
void	error_args(void);
void	clean_exit(t_pipe *data);
void	init_cmd(int argc, char **argv, t_pipe *data);
void	init_files(int argc, char **argv, t_pipe *data);
void	check_cmds(t_pipe *data, int argc);
void	error_fork(t_pipe *data);
void	free_pointer(char **pointer);

#endif
