/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:23:51 by pamanzan          #+#    #+#             */
/*   Updated: 2025/06/07 18:23:51 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	not_expansion(char **str, char *temp, char *end)
{
	char	*new_str;

	new_str = ft_strjoin(temp, end);
	if (!new_str)
	{
		free(temp);
		return (1);
	}
	free(temp);
	free(*str);
	*str = new_str;
	return (0);
}

char	*extract_expand(char *str, int i, t_env *data, char **end_ptr)
{
	char	*start;
	char	*end;
	char	*new_temp;
	char	*new_str;

	start = &str[i];
	end = start;
	while (*end && (ft_isalnum(*end) || *end == '_'))
		end++;
	new_temp = ft_strndup(start, end - start);
	new_str = expand_variable(new_temp, data);
	free(new_temp);
	*end_ptr = end;
	return (new_str);
}

int	build_new_string(char **str, char *temp, char *new_str, char *end)
{
	char	*new_temp;

	if (!new_str)
		return (not_expansion(str, temp, end));
	new_temp = ft_strjoin(new_str, end);
	new_str = ft_strjoin_free(temp, new_temp);
	free(*str);
	*str = ft_strdup(new_str);
	free(new_str);
	return (0);
}

int	dollar_search(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '$' && str[i])
		i++;
	if (str[i] == '$')
		return (i);
	return (0);
}
