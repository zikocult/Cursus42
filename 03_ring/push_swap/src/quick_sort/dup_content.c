/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:58:33 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/09/02 11:59:14 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	*cont_dup(t_content *head)
{
	int			i;
	int			*content;
	t_content	*curr;

	i = 0;
	curr = head;
	content = malloc(list_len(curr) * sizeof(int));
	if (!content)
		printerror(2, true);
	while (curr)
	{
		content[i] = curr->value;
		curr = curr->next;
		i++;
	}
	return (content);
}
