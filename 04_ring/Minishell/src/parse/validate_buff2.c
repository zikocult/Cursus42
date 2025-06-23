/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_buff2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:38:43 by gbaruls-          #+#    #+#             */
/*   Updated: 2025/06/07 11:10:08 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	check_parse_error(char c, int count)
{
	if ((c == '<' || c == '>') && count >= 3)
	{
		ft_putstr_fd("minishell: parse_error ", 2);
		ft_putchar_fd(c, 2);
		ft_putchar_fd('\n', 2);
		return (false);
	}
	if (c == '|' && count >= 2)
	{
		ft_putstr_fd("minishell: parse_error  |\n", 2);
		return (false);
	}
	return (true);
}
