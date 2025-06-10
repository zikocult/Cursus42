/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 20:55:48 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2025/06/02 21:06:03 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	set_bool(pthread_mutex_t *mutex, bool *dest, bool value)
{
	mutex_handle(mutex, LOCK);
	*dest = value;
	mutex_handle(mutex, UNLOCK);
}

void	set_long(pthread_mutex_t *mutex, long *dest, long value)
{
	mutex_handle(mutex, LOCK);
	*dest = value;
	mutex_handle(mutex, UNLOCK);
}

bool	get_bool(pthread_mutex_t *mutex, bool *value)
{
	bool	ret;
	mutex_handle(mutex, LOCK);
	ret = *value;
	mutex_handle(mutex, UNLOCK);
	return (ret);
}

bool	get_long(pthread_mutex_t *mutex, long *value)
{
	bool	ret;
	mutex_handle(mutex, LOCK);
	ret = *value;
	mutex_handle(mutex, UNLOCK);
	return (ret);
}

// REDUNDANT?
bool	simulation_finished(t_table *table)
{
	return (get_bool(&table->table_mutex, &table->end_simulation));
}
