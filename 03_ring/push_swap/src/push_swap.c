/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:11:46 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/08/29 11:30:38 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_push		data;

	if (argc < 2 || (argc == 2 && !argv[1][0]))
		printerror(1);
	else if (argc > 2)
		init_data_argc(argc, argv, &data);
	else if (argc == 2)
		init_data_argv(argv[1], &data);
	init_list(&data);
	// Desde aquí están mis tests
	// test(&data, argc);
	//Hasta aquí, todo esto se debe borrar
	if (!sorted_list(data.a_head))
	{
		if (list_len(data.a_head) == 2)
			sa(&data);
		else if (list_len(data.a_head)== 3)
			sortofthree(&data.a_head, &data);
		else
			push_swap(&data);
	}
	clean_exit(&data);
	return (0);
}
