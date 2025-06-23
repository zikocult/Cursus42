/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:47:18 by gbaruls-          #+#    #+#             */
/*   Updated: 2025/06/07 08:54:21 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*change_null(char *content, char *str)
{
	if (!content)
		return (" ");
	return (str);
}

void	export_list_builtin(t_env *data)
{
	t_var	*current;

	current = data->head;
	while (current->next)
	{
		if (!ft_strcmp(current->type, "env")
			|| !ft_strcmp(current->type, "exp"))
			printf("declare -x %s%s%s%s\n", current->var_name,
				change_null(current->content, "=\""),
				change_null(current->content, current->content),
				change_null(current->content, "\""));
		current = current->next;
	}
}
