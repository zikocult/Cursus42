/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:05:36 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/09/02 10:36:57 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include "../include/push_swap.h"
#include <stdbool.h>

static void	sort_list(t_push *data)
{
	if (list_len(data->a_head) == 2)
		sa(data, true);
	else if (list_len(data->a_head) == 3)
		sortofthree(&data->a_head, data);
	else
		turkey_sort(data);
}

int	main(int argc, char **argv)
{
	t_push		data;
	int			len;

	if (argc < 2 || (argc == 2 && !argv[1][0]))
		printerror(1, false);
	else if (argc > 2)
		init_data_argc(argc, argv, &data, true);
	else if (argc == 2)
		init_data_argv(argv[1], &data, true);
	init_list(&data, false);
	len = list_len(data.a_head);
	if (!sorted_list(data.a_head))
		sort_list(&data);
	if (sorted_list(data.a_head) && len == list_len(data.a_head))
		ft_putstr_fd("OK\n", 1);
	else
	{
		if (!sorted_list(data.a_head))
			ft_putstr_fd("Error: No sorted list\n", 2);
		if (len != list_len(data.a_head))
			ft_putstr_fd("Error: No all initial elements are in the list", 2);
		ft_putstr_fd("KO\n", 2);
	}
	clean_exit(&data);
	return (0);
}
