/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_redirections.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:29:58 by Guillem Bar       #+#    #+#             */
/*   Updated: 2025/06/07 11:47:14 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static bool	handle_redirection(char *cmd_buff, int *i, bool *empty_space)
{
	if (cmd_buff[*i] == ' ')
		*empty_space = true;
	while (cmd_buff[*i] == ' ')
		(*i)++;
	if (*empty_space && (cmd_buff[*i] == '<' || cmd_buff[*i] == '>'))
	{
		ft_putstr_fd("minishell: parse_error '", 2);
		ft_putstr_fd(&cmd_buff[*i], 2);
		ft_putstr_fd("'\n", 2);
		return (false);
	}
	*empty_space = false;
	return (true);
}

static bool	check_quotes(char c, bool *in_single_quotes, bool *in_double_quotes)
{
	if (c == '\'')
		*in_single_quotes = !*in_single_quotes;
	if (c == '"')
		*in_double_quotes = !*in_double_quotes;
	return (!*in_single_quotes && !*in_double_quotes);
}

bool	check_consecutive_redirections(char *cmd_buff)
{
	int		i;
	bool	empty_space;
	bool	in_single_quotes;
	bool	in_double_quotes;

	i = 0;
	empty_space = false;
	in_single_quotes = false;
	in_double_quotes = false;
	while (cmd_buff[i])
	{
		if (check_quotes(cmd_buff[i], &in_single_quotes, &in_double_quotes)
			&& (cmd_buff[i] == '<' || cmd_buff[i] == '>'))
		{
			i++;
			if (!handle_redirection(cmd_buff, &i, &empty_space))
				return (false);
		}
		else
			i++;
	}
	return (true);
}
