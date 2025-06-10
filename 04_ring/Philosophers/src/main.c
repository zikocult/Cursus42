/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:00:22 by gbaruls-          #+#    #+#             */
/*   Updated: 2025/06/02 17:01:59 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// number_of_philosophers time_to_die time_to_eat time_to_sleep [max_eats]
// Example: ./philo 	5  		  800		  200		  200			5
// ./philo 5 800 200 200 5
int	main(int argc, char **argv)
{
	t_table	table;

	write(1, "\033[2J\033[H", 7);
	if (argc == 5 || argc == 6)
	{
		parse_input(&table, argv);
		init_tables(&table);
		// dinner_start
		// Clean function
		printf(GREEN"The input is correct, congrats: %s\n"RESET, argv[0]);
	}
	else
		exit_error("🚨 INPUT ERROR!!!!! 🚨\n"
			GREEN"A correct example is: ./philo 5 800 200 200 [5]\n");
	return (EXIT_SUCCESS);
}
