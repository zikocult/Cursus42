/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:22:02 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/08/27 19:39:27 by Guillem Barulls  ###   ########.fr       */
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
}

void test (t_push *data, int argc)
{
	ft_printf("ARGC == %d\n", argc);
	ft_printf("Contador de valores = %d\n", data->count);
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

