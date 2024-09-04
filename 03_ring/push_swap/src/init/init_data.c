/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:30:55 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/09/04 16:53:51 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	init_heads(t_push *data)
{
	data->a_head = NULL;
	data->b_head = NULL;
	data->a_tail = NULL;
}

void	init_data_argv(char *argv, t_push *data, bool check)
{
	data->input = ft_split(argv, ' ');
	if (!data->input)
	{
		free_pointer(data->input);
		printerror(2, check);
	}
	init_heads(data);
}

void	init_data_argc(int argc, char **argv, t_push *data, bool check)
{
	int	i;

	i = 0;
	data->input = (char **)ft_calloc(argc, sizeof(char *));
	if (!data->input)
		printerror(2, check);
	while (i < argc - 1)
	{
		data->input[i] = ft_strdup(argv[i + 1]);
		if (!data->input[i])
		{
			free_pointer(data->input);
			printerror(2, check);
		}
		i++;
	}
	init_heads(data);
}

static void	check_duplicates(t_push *data, bool check)
{
	t_content	*curr;
	t_content	*dup;

	curr = data->a_head;
	while (curr != NULL)
	{
		dup = curr->next;
		while (dup != NULL)
		{
			if (curr->value == dup->value)
			{
				clean_exit(data);
				printerror(3, check);
			}
			dup = dup->next;
		}
		curr = curr->next;
	}
}

void	init_list(t_push *data, bool check)
{
	int		i;
	long	value;

	i = 0;
	while (data->input[i])
	{
		value = ft_atol(data->input[i]);
		if (value < INT_MIN || value > INT_MAX)
		{
			clean_exit(data);
			printerror(5, check);
		}
		if (value == 0)
		{
			if (!check_alpha(data->input[i]))
			{
				clean_exit(data);
				printerror(4, check);
			}
		}
		insert_end(&data->a_head, &data->a_tail, value, data);
		i++;
	}
	check_duplicates(data, check);
	init_med(data);
}
