/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:00:05 by pamanzan          #+#    #+#             */
/*   Updated: 2025/04/03 19:14:27 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	*create_node3(t_var *new_node, char *equal_sign, int name_length)
{
	new_node->type = ft_strdup("env");
	new_node->var_name[name_length] = '\0';
	new_node->content = ft_strdup(equal_sign + 1);
	if (!new_node->content)
	{
		free(new_node->var_name);
		free(new_node);
		return (NULL);
	}
	return (new_node);
}

void	*create_node2(char *env_var, t_var *new_node, char *equal_sign)
{
	size_t	name_length;
	size_t	i;

	name_length = equal_sign - env_var;
	i = 0;
	new_node->var_name = (char *)malloc(name_length + 1);
	if (!new_node->var_name)
	{
		free(new_node);
		return (NULL);
	}
	while (i < name_length)
	{
		new_node->var_name[i] = env_var[i];
		i++;
	}
	if (!create_node3(new_node, equal_sign, name_length))
		return (NULL);
	return (new_node);
}

t_var	*create_node(char *env_var)
{
	t_var	*new_node;
	char	*equal_sign;

	new_node = (t_var *)malloc(sizeof(t_var));
	if (!new_node)
		return (NULL);
	equal_sign = ft_strchr(env_var, '=');
	if (equal_sign)
	{
		if (!create_node2(env_var, new_node, equal_sign))
			return (NULL);
	}
	else
	{
		new_node->var_name = ft_strdup(env_var);
		if (!new_node->var_name)
		{
			free(new_node);
			return (NULL);
		}
		new_node->content = NULL;
	}
	new_node->next = NULL;
	return (new_node);
}

t_var	*insert_blank_node(t_env *data)
{
	t_var	*new_node;

	new_node = (t_var *)malloc(sizeof(t_var));
	if (!new_node)
		return (NULL);
	new_node->type = "\0";
	new_node->content = "\0";
	new_node->var_name = "\0";
	new_node->next = NULL;
	data->tail->next = new_node;
	data->tail = new_node;
	return (new_node);
}

t_var	*env_search(t_env *data, char *str)
{
	t_var	*current;

	current = data->head;
	while (current != NULL)
	{
		if (ft_strcmp(current->var_name, str) == 0)
			return (current);
		current = current->next;
	}
	return (NULL);
}
