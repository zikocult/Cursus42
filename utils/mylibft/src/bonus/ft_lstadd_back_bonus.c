/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:16:17 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/07/03 13:38:13 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstadd_back(t_list **lst, t_list *newlist)
{
	t_list	*last;

	if (!lst)
		return ;
	if (*lst == NULL)
	{
		*lst = newlist;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = newlist;
}
