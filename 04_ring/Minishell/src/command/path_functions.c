/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 09:42:45 by pamanzan          #+#    #+#             */
/*   Updated: 2025/06/07 08:20:12 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*get_full_path(char *path, char *command)
{
	char	*full_path;
	char	*temp_path;

	temp_path = ft_strjoin(path, "/");
	full_path = ft_strjoin(temp_path, command);
	free(temp_path);
	return (full_path);
}

char	*find_path(t_par *current, t_env *data)
{
	char	**paths;
	char	*full_path;
	int		i;
	t_var	*search;

	search = data->head;
	while (search && ft_strncmp(search->var_name, "PATH", 4) != 0)
		search = search->next;
	if (!search)
		return (NULL);
	paths = ft_split(search->content, ':');
	if (!paths || !*paths)
		return (NULL);
	i = 0;
	full_path = NULL;
	while (paths[i])
	{
		full_path = get_full_path(paths[i], current->command);
		if (access(full_path, X_OK) == 0)
			break ;
		free(full_path);
		full_path = NULL;
		i++;
	}
	return (free_memory(paths), full_path);
}

static int	path_messages(char *str)
{
	struct stat	info;

	if (access(str, F_OK))
		return (error_msg(str, 3), 126);
	if (stat(str, &info) != -1)
	{
		if (S_ISDIR(info.st_mode))
			return (error_msg(str, 0), 126);
	}
	if (access(str, X_OK))
		return (error_msg(str, 2), 126);
	return (0);
}

char	*check_path(t_par *current, t_env *data)
{
	char	*path;
	int		err_code;

	if (ft_strchr(current->command, '/'))
	{
		path = current->command;
		err_code = path_messages(current->command);
		if (err_code == 0)
			return (path);
		data->exit_var = err_code;
		return (NULL);
	}
	else
		path = find_path(current, data);
	if (!path)
	{
		error_msg(current->command, 1);
		data->exit_var = 127;
		return (NULL);
	}
	data->exit_var = 0;
	return (path);
}
