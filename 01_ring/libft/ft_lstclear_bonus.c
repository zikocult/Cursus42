/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:27:01 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/06/19 15:35:33 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!lst)
		return ;
	while (lst != NULL)
	{
		temp = ((*lst)->next);
		del((*lst)->content);
		free(*lst);
		(*lst) = temp;
	}
	free(*lst);
	*lst = NULL;
}
