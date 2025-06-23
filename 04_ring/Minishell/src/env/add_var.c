/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:34:40 by gbaruls-          #+#    #+#             */
/*   Updated: 2025/03/04 19:07:10 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	new_node1(t_env *data, char *name, char *content, char *type)
{
	t_var	*new_node;

	new_node = (t_var *)malloc(sizeof(t_var));
	if (!new_node)
		return ;
	new_node->type = ft_strdup(type);
	new_node->var_name = ft_strdup(name);
	if (content)
		new_node->content = ft_strdup(content);
	else
		new_node->content = NULL;
	data->last_node->next = new_node;
	new_node->next = data->tail;
	data->last_node = new_node;
}

static void	free_type(t_var *new_node, char *type)
{
	free(new_node->type);
	new_node->type = ft_strdup(type);
}

static void	new_node2(t_var *new_node, char *content, char *type)
{
	if (content)
	{
		free(new_node->content);
		new_node->content = ft_strdup(content);
	}
	else
	{
		if (new_node->content)
			free(new_node->content);
		new_node->content = NULL;
	}
	if (!ft_strcmp(type, "env"))
		free_type(new_node, type);
	else if (!ft_strcmp(type, "exp"))
	{
		if (ft_strcmp(new_node->type, "env"))
			free_type(new_node, type);
	}
	else
		free_type(new_node, type);
}

static void	new_node3(t_env *data, char *name, char *content, char *type)
{
	t_var	*new_node;

	new_node = (t_var *)malloc(sizeof(t_var));
	if (!new_node)
		return ;
	new_node->type = ft_strdup(type);
	new_node->var_name = ft_strdup(name);
	if (content)
		new_node->content = ft_strdup(content);
	else
		new_node->content = NULL;
	new_node->next = data->head;
	data->head = new_node;
	data->last_node = new_node;
}

int	add_elem(t_env *data, char *name, char *content, char *type)
{
	t_var	*new_node;

	if (data->head != data->tail)
	{
		new_node = env_search(data, name);
		if (!new_node)
			new_node1(data, name, content, type);
		else
			new_node2(new_node, content, type);
	}
	else
		new_node3(data, name, content, type);
	return (0);
}
