/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:05:36 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/08/30 18:21:17 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include "../libft/include/get_next_line.h"
#include "../include/push_swap.h"

static int	scmp(char *str_1, char *str_2)
{
	while (*str_1 == *str_2 && *str_1)
	{
		++str_1;
		++str_2;
	}
	return (*str_1 - *str_2);
}

static void	command_test(t_push *data, char *gnl)
{
	if (!scmp(gnl, "pa\n"))
		pa(data, false);
	else if (!scmp(gnl, "pb\n"))
		pb(data, false);
	else if (!scmp(gnl, "sa\n"))
		sa(data, false);
	else if (!scmp(gnl, "sb\n"))
		sb(data, false);
	else if (!scmp(gnl, "ss\n"))
		ss(data, false);
	else if (!scmp(gnl, "ra\n"))
		ra(data, false);
	else if (!scmp(gnl, "rb\n"))
		rb(data, false);
	else if (!scmp(gnl, "rr\n"))
		rr(data, false);
	else if (!scmp(gnl, "rra\n"))
		rra(data, false);
	else if (!scmp(gnl, "rrb\n"))
		rrb(data, false);
	else if (!scmp(gnl, "rrr\n"))
		rrr(data, false);
}

int	main(int argc, char **argv)
{
	t_push		data;
	char		*gnl;
	int			len;
	
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		ft_putstr_fd("KO\n", 2);
	else if (argc > 2)
		init_data_argc(argc, argv, &data);
	else if (argc == 2)
		init_data_argv(argv[1], &data);
	init_list(&data);
	len = list_len(data.a_head);
	gnl = get_next_line(0);
	while (gnl)
	{
		command_test(&data, gnl);
		gnl = get_next_line(0);
	}
	if (sorted_list(data.a_head) && len == list_len(data.a_head))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	clean_exit(&data);
	return (0);
}