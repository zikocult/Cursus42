/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_msg_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 08:57:32 by pamanzan          #+#    #+#             */
/*   Updated: 2025/06/07 10:36:25 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	env_msg_error(char *str, int flag)
{
	ft_putstr_fd("env: ", 2);
	if (flag == 0)
		error_msg(str, 3);
}
