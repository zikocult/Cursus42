/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:22:02 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/08/29 11:42:37 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	mostrar_lista(t_push *data)
{
	int i;
	t_content *curr, *curr2;

	curr = data->a_head;
	curr2 = data->b_head;
	i = 0;
	ft_printf("lista A\n");
	while (curr != NULL)
	{
		ft_printf("[%d]: %d\n", i, curr->value);
		curr = curr->next;
		i++;
	}
	i = 0;
	ft_printf("\nlista B\n");
	while (curr2 != NULL)
	{
		ft_printf("[%d]: %d\n", i, curr2->value);
		curr2 = curr2->next;
		i++;
	}
	ft_printf("-----------\n\n");
}

void	muestra_struct(t_content *head)
{
	t_content	*curr;
	
	curr = head;
	while (curr != NULL)
	{
		ft_printf("Value : %d\n", curr->value);
		ft_printf("Position : %d\n", curr->position);
		ft_printf("Price : %d\n", curr->price);
		ft_printf("Under median : %d\n", curr->under_median);
		ft_printf("Best : %d\n", curr->best);
		ft_printf("Target : %d\n", curr->target->value);
		ft_printf("-----------\n\n");
		curr = curr->next;
	}
}

void test (t_push *data, int argc)
{
	ft_printf("ARGC == %d\n", argc);
	ft_printf("Contador de valores = %d\n", list_len(data->a_head));
	ft_printf("\n-------Mostrando la lista--------\n");
	mostrar_lista(data);
	ft_printf("\n-------Push--------\n");
	pb(data);
	pb(data);
	pb(data);
	pa(data);
	pb(data);
	mostrar_lista(data);
	ft_printf("\n-------Swap--------\n");
	sa(data);
	sa(data);
	ss(data);
	sb(data);
	sb(data);
	mostrar_lista(data);
	ft_printf("\n-------Rotate--------\n");
	ra(data);
	rb(data);
	mostrar_lista(data);
	ft_printf("\n-------Reverse Rotate--------\n");
	rra(data);
	rrb(data);
	mostrar_lista(data);
}

