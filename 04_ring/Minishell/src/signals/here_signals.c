/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_signals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:47:18 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2025/06/07 10:47:19 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	handle_sigint_heredoc(int sig)
{
	(void)sig;
	exit(130);
}

void	here_signals(void)
{
	signal(SIGINT, handle_sigint_heredoc);
	signal(SIGQUIT, SIG_IGN);
}
