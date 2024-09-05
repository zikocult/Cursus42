/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:05:36 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/09/05 10:55:15 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include "../libft/include/get_next_line.h"
#include "../include/push_swap.h"
#include <stdbool.h>

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
	else
		data->check_commands = false;
}

static void	final_check(t_push *data, int len)
{
	if (sorted_list(data->a_head) && len == list_len(data->a_head)
		&& data->check_commands == true)
		ft_putstr_fd("OK\n", 1);
	else
	{
		if (data->check_commands == false)
			ft_putstr_fd("Error: Wrong output\n", 2);
		if (!sorted_list(data->a_head))
			ft_putstr_fd("Error: No sorted list\n", 2);
		else if (len != list_len(data->a_head))
			ft_putstr_fd("Error: No all initial elements are in the list\n", 2);
		ft_putstr_fd("Error\n", 2);
	}
}

int	main(int argc, char **argv)
{
	t_push		data;
	char		*gnl;
	int			len;

	data.check_commands = true;
	if (argc < 2)
		return (0);
	else if (argc == 2 && (!argv[1][0] || argv[1][0] == 32
			|| (argv[1][0] >= 9 && argv[1][0] <= 13)))
		printerror(6, false);
	else if (argc > 2)
		init_data_argc(argc, argv, &data, false);
	else if (argc == 2)
		init_data_argv(argv[1], &data, false);
	init_list(&data, false);
	len = list_len(data.a_head);
	gnl = get_next_line(0);
	while (gnl)
	{
		command_test(&data, gnl);
		gnl = get_next_line(0);
	}
	final_check(&data, len);
	clean_exit(&data);
	return (0);
}
