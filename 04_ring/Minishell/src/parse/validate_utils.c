/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:46:46 by gbaruls-          #+#    #+#             */
/*   Updated: 2025/02/06 16:15:48 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	validation_reset(int *count, char *last_char)
{
	*count = 0;
	*last_char = '\0';
}

void	jump_single_quotes(char *cmd_buff, int *i)
{
	if (cmd_buff[*i] == '\'')
	{
		(*i)++;
		while (cmd_buff[*i] != '\'' && cmd_buff[*i])
			(*i)++;
		if (cmd_buff[*i] == '\'')
			(*i)++;
	}
}

void	jump_double_quotes(char *cmd_buff, int *i)
{
	if (cmd_buff[*i] == '"')
	{
		(*i)++;
		while (cmd_buff[*i] != '"' && cmd_buff[*i])
			(*i)++;
		if (cmd_buff[*i] == '"')
			(*i)++;
	}
}

void	init_vars(int *i, int *count, char *last_char)
{
	*i = 0;
	*count = 0;
	*last_char = '\0';
}
