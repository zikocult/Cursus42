/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_remove_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:16:05 by Guillem Bar       #+#    #+#             */
/*   Updated: 2025/05/02 17:40:07 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static size_t	calculate_new_length(const char *str)
{
	size_t	new_len;

	new_len = 0;
	while (*str)
	{
		if (*str != '"')
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
		if (*str != '"')
			*dst++ = *str;
		str++;
	}
	*dst = '\0';
	return (temp);
}

char	*remove_double_quotes(char *str)
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

static void	while_reduction_parameter(t_par *current)
{
	int	i;

	i = 0;
	while (current->parameter[i])
	{
		if (!search_dollar_parse(current->parameter[i]))
			current->parameter[i] = return_str_parse(current->parameter[i]);
		i++;
	}
}

void	remove_quotes_from_par2(t_par *current, int i)
{
	if (!search_dollar_parse(current->command))
		current->command = return_str_parse(current->command);
	if (current->parameter)
		while_reduction_parameter(current);
	i = 0;
	if (current->infile)
	{
		while (current->infile[i])
		{
			if (!search_dollar_parse(current->infile[i])
				&& current->infile[i][0] != '<')
				current->infile[i] = return_str_parse(current->infile[i]);
			i++;
		}
	}
	i = 0;
	if (current->outfile)
	{
		while (current->outfile[i])
		{
			if (!search_dollar_parse(current->outfile[i]))
				current->outfile[i] = return_str_parse(current->outfile[i]);
			i++;
		}
	}
}
