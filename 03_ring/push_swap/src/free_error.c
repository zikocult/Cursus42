/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:27:23 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/08/26 22:16:34 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	deallocate(t_content **tail, t_content **head)
{
	t_content	*curr;

	curr = *tail;
	if (*tail == NULL)
		return ;
	while (curr->next != NULL)
	{
		curr = curr->next;
		free(curr->prev);
	}
	free(curr);
	*tail = NULL;
	*head = NULL;
}

void	printerror(int error)
{
	if (error == 1)
		ft_printf("Invalid number of arguments\n");
	if (error == 2)
		ft_printf("Invalid allocation memory\n");
	exit (error);
}

void	free_pointer(char **pointer)
{
	int	i;

	i = 0;
	while (pointer[i])
		i++;
	while (i >= 0)
	{
		free(pointer[i]);
		i--;
	}
	free(pointer);
}

void	clean_exit(t_push *data)
{
	free_pointer(data->input);
	deallocate(&data->a_tail, &data->a_head);
	deallocate(&data->b_tail, &data->b_head);
}
