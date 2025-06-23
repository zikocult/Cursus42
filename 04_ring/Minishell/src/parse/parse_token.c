/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:37:06 by Guillem Bar       #+#    #+#             */
/*   Updated: 2025/02/06 16:18:04 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	process_token(char *start, char *end, int *mode, t_parse *data)
{
	char	*token;

	token = ft_strndup(start, end - start);
	if (*mode == 1)
		append_parameter(&data->infile, token, *mode);
	else if (*mode == 2)
		append_parameter(&data->outfile, token, *mode);
	else if (*mode == 3)
		append_parameter(&data->infile, token, *mode);
	else if (*mode == 4)
		append_parameter(&data->outfile, token, *mode);
	else if (!data->command)
		data->command = token;
	else
		append_parameter(&data->parameter, token, *mode);
	if (*mode >= 1 && *mode <= 4)
		*mode = 0;
}

char	*handle_special_char(char *end, int *mode, t_parse *data)
{
	if (*end == '|')
		add_node(data);
	else if (*end == '<')
	{
		if (*(end + 1) == '<')
		{
			*mode = 3;
			end++;
		}
		else
			*mode = 1;
	}
	else if (*end == '>')
	{
		if (*(end + 1) == '>')
		{
			*mode = 4;
			end++;
		}
		else
			*mode = 2;
	}
	return (end);
}

static bool	between_double_quotes(char **end, int *in_quotes)
{
	if (**end == '"')
	{
		*in_quotes = !(*in_quotes);
		(*end)++;
		return (true);
	}
	return (false);
}

static bool	between_single_quotes(char **end, int *in_quotes)
{
	if (**end == '\'')
	{
		*in_quotes = !(*in_quotes);
		(*end)++;
		return (true);
	}
	return (false);
}

void	parse_token(char *cmd_buff, t_parse *data)
{
	char	*start;
	char	*end;

	start = cmd_buff;
	end = cmd_buff;
	data->mode = 0;
	while (*end)
	{
		if (between_double_quotes(&end, &data->in_double_quotes)
			|| between_single_quotes(&end, &data->in_single_quotes))
			continue ;
		if (!data->in_single_quotes && !data->in_double_quotes && (*end == ' '
				|| *end == '|' || *end == '<' || *end == '>'))
		{
			if (start != end)
				process_token(start, end, &data->mode, data);
			end = handle_special_char(end, &data->mode, data);
			start = end + 1;
		}
		end++;
	}
	if (start != end)
		process_token(start, end, &data->mode, data);
	add_node(data);
	remove_quotes_from_par(data->head);
}
