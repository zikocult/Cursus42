/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 08:06:19 by pamanzan          #+#    #+#             */
/*   Updated: 2025/06/07 08:14:59 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	handle_dollar_expansion(char **str, t_env *data, int i, char *temp)
{
	char	*new_str;
	char	*end;

	if ((*str)[i++] == '$')
	{
		if (!(*str)[i])
			return (free(temp), 0);
		if ((*str)[i] == '?')
			handle_question(str, i, temp, data);
		else
		{
			new_str = extract_expand(*str, i, data, &end);
			return (build_new_string(str, temp, new_str, end), 1);
		}
	}
	return (0);
}

int	handle_dollar(char **str, t_env *data)
{
	int		i;
	char	*temp;

	if (ft_strcmp(*str, "$\"\"") == 0 || ft_strcmp(*str, "$\'\'") == 0)
	{
		free(*str);
		*str = ft_strdup("");
		return (0);
	}
	if (ft_strchr(*str, '$') && !ft_strchr(*str, '\'')
		&& !ft_strchr(*str, '\"'))
	{
		i = dollar_search(*str);
		temp = ft_strndup(*str, i);
		return (handle_dollar_expansion(str, data, i, temp));
	}
	return (0);
}
