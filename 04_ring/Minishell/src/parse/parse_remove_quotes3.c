/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_remove_quotes3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:34:16 by gbaruls-          #+#    #+#             */
/*   Updated: 2025/02/17 16:36:11 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	remove_quotes_from_par(t_par *current)
{
	while (current)
	{
		remove_quotes_from_par2(current, 0);
		current = current->next;
	}
}
