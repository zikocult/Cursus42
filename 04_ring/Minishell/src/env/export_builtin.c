/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:39:26 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2025/05/19 17:26:28 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	change_type(char *str, t_env *data)
{
	t_var	*current;

	current = NULL;
	current = env_search(data, str);
	if (current && ft_strcmp(current->type, "env"))
	{
		free(current->type);
		current->type = ft_strdup("env");
	}
	else if (!current)
		add_elem(data, str, NULL, "exp");
}

int	export_builtin(char *str, t_env *data)
{
	char	*var;
	char	*value;
	int		count;

	count = 0;
	if (ft_strchr(str, '='))
	{
		var = create_var(str);
		while (str[count] != '=' && str[count])
			count++;
		value = create_value((str + count + 1));
		add_elem(data, var, value, "env");
		free (var);
		free(value);
	}
	else
		change_type(str, data);
	return (0);
}

int	run_export(t_env *data, char **str)
{
	int	i;
	int	count;
	int	ret;

	i = 0;
	if (!str)
	{
		export_list_builtin(data);
		return (0);
	}
	count = count_args_double_pointer(str);
	while (i < count)
	{
		ret = export_builtin(str[i], data);
		i++;
	}
	return (ret);
}
