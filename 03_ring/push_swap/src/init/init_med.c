/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_med.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:12:27 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/09/04 17:01:11 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	pusht_to_b(t_push *data, bool check)
{
	t_content	*curr;

	curr = data->a_head;
	pb(data, check);
	if (curr->value > data->median)
		rr(data, check);
}

static void	sort_temp_value(int *list, int len)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (list[j] > list[j + 1])
			{
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	init_med(t_push *data)
{
	int			i;
	int			*temp_value;
	t_content	*curr;

	i = 0;
	curr = data->a_head;
	temp_value = malloc(list_len(data->a_head) * sizeof(int));
	if (!temp_value)
	{
		printerror(2, true);
		clean_exit(data);
	}
	while (curr)
	{
		temp_value[i] = curr->value;
		i++;
		curr = curr->next;
	}
	sort_temp_value(temp_value, list_len(data->a_head));
	data->median = temp_value[list_len(data->a_head) / 2];
	free(temp_value);
}
