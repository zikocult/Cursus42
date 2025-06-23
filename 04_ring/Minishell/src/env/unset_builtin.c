/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:40:22 by gbaruls-          #+#    #+#             */
/*   Updated: 2025/04/09 17:33:23 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_var	*env_prev_search(t_env *data, char *str)
{
	t_var	*current;

	current = data->head;
	if (current)
	{
		while (current->next)
		{
			if (!ft_strcmp(current->next->var_name, str))
				return (current);
			current = current->next;
		}
	}
	return (NULL);
}

void	unset_builtin(t_env *data, char *str)
{
	t_var	*del_node;
	t_var	*current;

	del_node = NULL;
	if (!ft_strcmp(data->head->var_name, str))
	{
		del_node = data->head;
		data->head = del_node->next;
	}
	else
	{
		current = env_prev_search(data, str);
		if (current)
		{
			del_node = current->next;
			current->next = del_node->next;
		}
	}
	if (del_node)
	{
		free(del_node->type);
		free(del_node->content);
		free(del_node->var_name);
		free(del_node);
	}
}

int	run_unset(t_env *data, char **str)
{
	int	i;
	int	count;

	i = 0;
	if (!str)
		return (0);
	count = count_args_double_pointer(str);
	while (i < count)
	{
		unset_builtin(data, str[i]);
		i++;
	}
	return (0);
}
