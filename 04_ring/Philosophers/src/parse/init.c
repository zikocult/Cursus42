/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 18:48:51 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2025/06/02 20:53:08 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static void	philo_init(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < table->philo_nbr)
	{
		philo = table->philos + i;
		philo->id = i + 1;
		philo->full = false;
		philo->meals_counter = 0;
		philo->table = table;
		if (philo->id % 2)
		{
			philo->first_fork = &table->forks[i];
			philo->second_fork = &table->forks[(i + 1) % table->philo_nbr];
		}
		else
		{
			philo->first_fork = &table->forks[(i + 1) % table->philo_nbr];
			philo->second_fork = &table->forks[i];
		}
		i++;
	}
}

// static void	print_structures(t_table *table)
// {
// 	int i = 0;
//
// 	printf(RED"Table structure:\n"RESET"philo number: %d\n"
// 		"time to die: %ld\ntime to eat: %ld\ntime to sleep: %ld\n"
// 		"limit of meals: %d\n\n",
// 		table->philo_nbr, table->time_to_die, table->time_to_eat,
// 		table->time_to_sleep, table->nbr_limit_meals);
// 	while (i < table->philo_nbr)
// 	{
// 		printf(YELLOW"Philo id: %d Structure: %d\n"RESET, 
// 		 			table->philos[i].id, i);
// 		printf("meals_counter: %d\n", table->philos[i].meals_counter);
// 		printf("full: %d\n", table->philos[i].full);
// 		printf("last meal: %ld\n", table->philos[i].last_meal_time);
// 		printf("first fork: %d\n", table->philos[i].first_fork->fork_id);
// 		printf("second fork: %d\n\n", table->philos[i].second_fork->fork_id);
// 		i++;
// 	}
// }
//
void	init_tables(t_table *table)
{
	int	i;

	i = 0;
	table->end_simulation = false;
	table->all_thread = false;
	table->philos = protect_malloc(sizeof(t_philo) * table->philo_nbr);
	table->forks = protect_malloc(sizeof(t_fork) * table->philo_nbr);
	mutex_handle(&table->table_mutex, INIT);
	while (i < table->philo_nbr)
	{
		mutex_handle(&table->forks[i].fork, INIT);
		table->forks[i].fork_id = i;
		i++;
	}
	philo_init(table);
}
