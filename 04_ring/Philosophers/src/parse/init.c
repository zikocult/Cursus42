/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 18:48:51 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2025/05/30 20:36:28 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/philo.h"

static void	assign_forks(t_philo *philo, t_fork *fork, int i)
{
	int	nbr;

	nbr = philo->table->philo_nbr;
	if (philo->id % 2)
	{
		philo->first_fork = &fork[i];
		philo->second_fork = &fork[(i + 1) % nbr];
	}
	else	
	{
		philo->first_fork = &fork[(i + 1) % nbr];
		philo->second_fork = &fork[i];
	}
}

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
		assign_forks(philo, table->forks, i);
		i++;
	}
}

void	init_tables(t_table *table)
{
	int	i;

	i = 0;
	table->end_simulation = false;
	table->philos = protect_malloc(sizeof(t_philo) * table->philo_nbr);
	table->forks = protect_malloc(sizeof(t_fork) * table->philo_nbr);
	while (i < table->philo_nbr)
	{
		mutex_handle(&table->forks[i].fork, INIT);
		table->forks[i].fork_id = i;
		i++;
	}
	philo_init(table);
}
