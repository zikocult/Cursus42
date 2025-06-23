/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_remove_quotes2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:41:12 by gbaruls-          #+#    #+#             */
/*   Updated: 2025/02/17 20:54:36 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static size_t	calculate_new_length(const char *str)
{
	size_t	new_len;

	new_len = 0;
	while (*str)
	{
		if (*str != '\'')
			new_len++;
		str++;
	}
	return (new_len);
}

static char	*create_new_string(const char *str, size_t new_len)
{
	char	*temp;
	char	*dst;

	temp = (char *)ft_calloc(new_len + 1, sizeof(char));
	dst = temp;
	if (!temp)
		return (NULL);
	while (*str)
	{
		if (*str != '\'')
			*dst++ = *str;
		str++;
	}
	*dst = '\0';
	return (temp);
}

char	*remove_single_quotes(char *str)
{
	size_t	new_len;
	char	*new_str;

	if (!str)
		return (NULL);
	new_len = calculate_new_length(str);
	new_str = create_new_string(str, new_len);
	if (!new_str)
		return (NULL);
	free(str);
	return (new_str);
}

bool	search_dollar_parse(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (false);
	while (str[i])
	{
		if (str[i] == '$')
			return (true);
		i++;
	}
	return (false);
}

char	*return_str_parse(char *str)
{
	if (!str)
		return (NULL);
	str = remove_single_quotes(str);
	str = remove_double_quotes(str);
	return (str);
}
