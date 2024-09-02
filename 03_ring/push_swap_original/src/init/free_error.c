/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:27:23 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/09/02 10:43:24 by Guillem Barulls  ###   ########.fr       */
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

void	printerror(int error, bool check)
{
	if (error == 1)
		ft_putstr_fd("Error: Instruction doesn't exist\n", 2);
	if (error == 2)
		ft_putstr_fd("Error: Invalid allocation memory\n", 2);
	if (error == 3)
		ft_putstr_fd("Error: There are duplicate values\n", 2);
	if (error == 4)
		ft_putstr_fd("Error: Incorrect format\n", 2);
	if (error == 5)
		ft_putstr_fd("Error: Some numbers are bigger than integer\n", 2);
	if (!check)
		ft_putstr_fd("KO\n", 2);
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
