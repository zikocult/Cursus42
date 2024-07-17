/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:49:11 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/07/17 12:52:53 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdio.h>

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int swapped = 1;
	t_list *ptr1;
	t_list *lptr = NULL;

	if (lst == NULL)
		return (NULL);
	while (swapped)
	{
		swapped = 0;
		ptr1 = lst;
		while (ptr1->next != lptr)
		{
			if (!cmp(ptr1->data, ptr1->next->data))
			{
				int temp = ptr1->data;
				ptr1->data = ptr1->next->data;
				ptr1->next->data = temp;
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	}
	return (lst);
}

