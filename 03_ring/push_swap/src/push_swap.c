/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:11:46 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/09/04 18:04:40 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_push		data;

	if (argc < 2)
		return (0);
	else if (argc == 2 && !argv[1][0])
		printerror(4, true);
	else if (argc > 2)
		init_data_argc(argc, argv, &data, true);
	else if (argc == 2)
		init_data_argv(argv[1], &data, true);
	init_list(&data, true);
	if (!sorted_list(data.a_head))
	{
		if (list_len(data.a_head) == 2)
			sa(&data, true);
		else if (list_len(data.a_head) == 3)
			sortofthree(&data.a_head, &data);
		else
			turkey_sort(&data);
	}
	clean_exit(&data);
	return (0);
}
