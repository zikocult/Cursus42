/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:27:23 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/08/27 22:56:06 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	deallocate(t_content **head)
{
	t_content	*curr;

	curr = *head;
	if (*head == NULL)
		return ;
	while (curr->next != NULL)
	{
		curr = curr->next;
		free(curr->prev);
	}
	free(curr);
}

void	printerror(int error)
{
	if (error == 1)
		ft_printf("Error: Invalid number of arguments\n");
	if (error == 2)
		ft_printf("Error: Invalid allocation memory\n");
	if (error == 3)
		ft_printf("Error: Duplicated values\n");
	if (error == 4)
		ft_printf("Error: No numeric parameter included in the arguments\n");
	if (error == 5)
		ft_printf("Error: Number exceed the integers limit\n");
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
	deallocate(&data->a_head);
	deallocate(&data->b_head);
}
