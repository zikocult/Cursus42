/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:30:55 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/08/26 22:17:03 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	init_heads(t_push *data)
{
	data->a_tail = NULL;
	data->a_head = NULL;
	data->b_tail = NULL;
	data->b_head = NULL;
}

void	init_data_argv(char *argv, t_push *data)
{
	data->input = ft_split(argv, ' ');
	init_heads(data);
}

void	init_data_argc(int argc, char **argv, t_push *data)
{
	int	i;

	i = 0;
	data->input = (char **)ft_calloc(argc, sizeof(char *));
	if (!data->input)
		printerror(2);
	while (i < argc - 1)
	{
		data->input[i] = ft_strdup(argv[i + 1]);
		if (!data->input[i])
		{
			free_pointer(data->input);
			printerror(2);
		}
		i++;
	}
	init_heads(data);
}

void	init_list(t_push *data)
{
	int	i;

	i = 0;
	while (data->input[i])
	{
		insert_end(&data->a_tail, &data->a_head, ft_atoi(data->input[i]), data);
		i++;
	}
}
