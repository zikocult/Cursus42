/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 09:23:05 by patri             #+#    #+#             */
/*   Updated: 2025/04/03 19:31:06 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	init_envi_list3(t_env *data)
{
	char	cwd[PATH_MAX];

	getcwd(cwd, sizeof(cwd));
	data->head->var_name = ft_strdup("PWD");
	data->head->content = ft_strdup(cwd);
	data->head->type = ft_strdup("env");
}

static void	init_envi_list2(t_var *new_node, t_var *new_node2, t_var *new_node3)
{
	new_node->next = new_node2;
	new_node2->type = ft_strdup("env");
	new_node2->var_name = ft_strdup("SHLVL");
	new_node2->content = ft_strdup("1");
	new_node2->next = new_node3;
	new_node3->type = ft_strdup("env");
	new_node3->var_name = ft_strdup("_");
	new_node3->content = ft_strdup("/usr/bin/env");
	new_node3->next = NULL;
}

void	init_envi_list(t_env *data)
{
	t_var	*new_node;
	t_var	*new_node2;
	t_var	*new_node3;

	new_node = (t_var *)malloc(sizeof(t_var));
	if (!new_node)
		return ;
	new_node2 = (t_var *)malloc(sizeof(t_var));
	if (!new_node2)
		return ;
	new_node3 = (t_var *)malloc(sizeof(t_var));
	if (!new_node2)
		return ;
	data->head = new_node;
	data->last_node = new_node3;
	data->tail = new_node3;
	init_envi_list2(new_node, new_node2, new_node3);
	init_envi_list3(data);
	insert_blank_node(data);
}

static void	init_list2(t_env *data, t_var *new_node)
{
	data->head = new_node;
	data->tail = new_node;
}

void	init_list(t_env *data, char **env)
{
	t_var	*new_node;
	int		i;

	i = 0;
	while (env[i])
	{
		new_node = create_node(env[i]);
		if (!new_node)
		{
			free_list(data);
			return ;
		}
		if (!data->head)
			init_list2(data, new_node);
		else
		{
			data->tail->next = new_node;
			data->tail = new_node;
		}
		i++;
	}
	data->last_node = data->tail;
	insert_blank_node(data);
}
