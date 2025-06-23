/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_buff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:29:00 by Guillem Bar       #+#    #+#             */
/*   Updated: 2025/06/07 11:02:48 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static bool	check_pipe_error(char *cmd_buff, int i)
{
	bool	test;

	test = false;
	while (cmd_buff[i + 1] != '|' && cmd_buff[i + 1] && test == false)
	{
		if (cmd_buff[i + 1] != ' ')
			test = true;
		i++;
	}
	if (test == false)
	{
		ft_putstr_fd("minishell: parse_error |\n", 2);
		return (false);
	}
	return (true);
}

static void	update_count_and_last_char(char c, char *last_char, int *count)
{
	if (c == *last_char)
		(*count)++;
	else
	{
		*count = 1;
		*last_char = c;
	}
}

static bool	validate_cmdbuff2(char *cmd_buff)
{
	if (!cmd_buff || !*cmd_buff)
		return (false);
	if (!check_consecutive_redirections(cmd_buff))
		return (false);
	return (true);
}

static bool	validate_cmdbuff3(char *cmd_buff, char *last_char, int *count,
		int i)
{
	update_count_and_last_char(cmd_buff[i], last_char, count);
	if (!check_parse_error(cmd_buff[i], *count))
		return (false);
	if (!check_pipe_error(cmd_buff, i))
		return (false);
	return (true);
}

bool	validate_cmdbuff(char *cmd_buff)
{
	int		i;
	int		count;
	char	last_char;

	if (!validate_quotes(cmd_buff) || !validate_cmdbuff2(cmd_buff)
		|| !len_buff(cmd_buff))
		return (false);
	init_vars(&i, &count, &last_char);
	while (i < (int)ft_strlen(cmd_buff) && cmd_buff[i] != '\0')
	{
		jump_single_quotes(cmd_buff, &i);
		jump_double_quotes(cmd_buff, &i);
		if (i >= (int)ft_strlen(cmd_buff))
			break ;
		if (cmd_buff[i] == '<' || cmd_buff[i] == '>' || cmd_buff[i] == '|')
		{
			if (!validate_cmdbuff3(cmd_buff, &last_char, &count, i))
				return (false);
		}
		else
			validation_reset(&count, &last_char);
		i++;
	}
	return (true);
}
