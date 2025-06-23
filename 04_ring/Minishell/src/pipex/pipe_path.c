/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 09:49:24 by pamanzan          #+#    #+#             */
/*   Updated: 2025/04/12 12:52:54 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*create_env_var(char *name, char *value)
{
	char	*var;
	int		len;

	len = ft_strlen(name) + ft_strlen(value) + 2;
	var = (char *)malloc(len);
	if (!var)
		return (NULL);
	ft_strcpy(var, name);
	ft_strcat(var, "=");
	ft_strcat(var, value);
	return (var);
}

char	**enviroment(t_env *data)
{
	t_var	*var;
	char	**env;
	int		i;
	int		count;

	count = count_vars(data);
	env = (char **)malloc((count + 1) * sizeof(char *));
	if (!env)
		return (NULL);
	i = 0;
	var = data->head;
	while (var)
	{
		env[i] = create_env_var(var->var_name, var->content);
		if (!env[i])
		{
			free_array(env, i);
			return (NULL);
		}
		i++;
		var = var->next;
	}
	env[i] = NULL;
	return (env);
}

int	**create_big_pip(int num_pipes)
{
	int	**pipes;
	int	i;

	pipes = malloc(num_pipes * sizeof(int *));
	if (pipes == NULL)
		malloc_error("Error al asignar memoria");
	i = 0;
	while (i < num_pipes)
	{
		pipes[i] = malloc(2 * sizeof(int));
		if (pipes[i] == NULL)
		{
			perror("Error al asignar memoria");
			while (i > 0)
				free(pipes[--i]);
			free(pipes);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (pipes);
}
