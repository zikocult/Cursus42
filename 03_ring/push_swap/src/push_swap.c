/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:11:46 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/08/26 22:17:58 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_push		data;

	if (argc < 2)
		printerror(1);
	else if (argc > 2)
		init_data_argc(argc, argv, &data);
	else if (argc == 2)
		init_data_argv(argv[1], &data);
	init_list(&data);
	clean_exit(&data);
	return (0);
}
	// Desde aquí están mis tests
	// int i = 0;
	// ft_printf("ARGC == %d\n", argc);
	// while (data.input[i])
	// {
	// 	ft_printf("[%d]: %s\n", i, data.input[i]);
	// 	i++;
	// }
	// ft_printf("\n-------Mostrando la lista--------\n");
	// t_content	*curr = data.a_tail;
	// i = 0;
	// while (curr != NULL)
	// {
	// 	ft_printf("[%d]: %d\n", i, curr->value);
	// 	curr = curr->next;
	// 	i++;
	// }
	//Hasta aquí, todo esto se debe borrar
