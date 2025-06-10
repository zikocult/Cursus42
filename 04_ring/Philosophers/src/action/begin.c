/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:57:34 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2025/06/03 13:16:15 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static void	*action_simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_all_threads(philo->table);
	while (!simulation_finished(philo->table))
	{
		if (philo->full)
			break ;
		//eat();
		//sleep();
		//thinking();
	}
	return (NULL);
}

/*
* 	Actual action_begin:
* 	./philo 5 800 200 200 [5]
* 		- Si no hi ha menjar torna (table.nbr_limit_meals = 0)
*   	- Si només hi ha una filòsof s'haurà de fer un funció particular
*   	- Crear tots els fils i tots els filòsofs
*   	- Crear un monitor dels fils per veure quan moren
*   	- Sincronitzar el començament de la simulació amb tots els filòsofs
*   	- Juntar-ho tot
*/

void	action_begin(t_table *table)
{
	int	i;

	i = 0;
	if (table->philo_nbr == 0)
		return ;
	else if (table->philo_nbr == 1)
		; //TODO
	else
		while (i++ < table->philo_nbr)
			thread_handle(&table->philos[i].thread_id, action_simulation,
				 &table->philos[i], CREATE);
	table->start_simulation = gettime(MILLISECOND);
	set_bool(&table->table_mutex, &table->all_thread, true);
	i = 0;
	while (i++ < table->philo_nbr)
		thread_handle(&table->philos[i].thread_id, NULL, NULL, JOIN);
}
