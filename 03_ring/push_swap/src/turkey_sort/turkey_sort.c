/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkey_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 22:52:37 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/09/04 16:30:57 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	finish_rotation(t_content **head, t_content *node, char list,
					t_push *data)
{
	while (*head != node)
	{
		if (list == 'a')
		{
			if (node->under_median)
				ra(data, true);
			else
				rra(data, true);
		}
		if (list == 'b')
		{
			if (node->under_median)
				rb(data, true);
			else
				rrb(data, true);
		}
	}
}

void	reverse_rotate_both(t_content **head_a, t_content **head_b,
						t_content *cheap, t_push *data)
{
	while (*head_a != cheap->target && *head_b != cheap)
		rrr(data, true);
	set_position(*head_a);
	set_position(*head_b);
}

void	rotate_both(t_content **head_a, t_content **head_b,
				t_content *cheap, t_push *data)
{
	while (*head_a != cheap->target && *head_b != cheap)
		rr(data, true);
	set_position(*head_a);
	set_position(*head_b);
}

void	move_nodes(t_content **head_a, t_content **head_b, t_push *data)
{
	t_content	*cheap;

	cheap = cheap_node(*head_b);
	if (cheap->under_median && cheap->target->under_median)
		rotate_both(head_a, head_b, cheap, data);
	else if (!(cheap->under_median) && !(cheap->target->under_median))
		reverse_rotate_both(head_a, head_b, cheap, data);
	if (*head_b != cheap)
		finish_rotation(head_b, cheap, 'b', data);
	if (*head_a != cheap->target)
		finish_rotation(head_a, cheap->target, 'a', data);
	pa(data, true);
}

void	turkey_sort(t_push *data)
{
	int			len_a;

	len_a = list_len(data->a_head);
	if (len_a == 5)
		five_elements(&data->a_head, &data->b_head, data);
	else
	{
		while (len_a-- > 3)
			pusht_to_b(data, true);
	}
	sortofthree(&data->a_head, data);
	while (data->b_head)
	{
		init_nodes(data->a_head, data->b_head);
		move_nodes(&data->a_head, &data->b_head, data);
	}
	set_position(data->a_head);
	up_min_a(data);
}
