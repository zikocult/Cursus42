/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:08:25 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2025/05/30 19:50:40 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/philo.h"

static void	handle_mutex_error(int status, t_codes mutexcode)
{
	if (status == 0)
		return ;
	if (status == EINVAL && (mutexcode == LOCK || mutexcode == UNLOCK))
		exit_error("The value specified by mutex is invalid\n");
	else if (status == EINVAL && mutexcode == INIT)
		exit_error("The value specified by attr is invalid\n");
	else if (status == EDEADLK)
		exit_error("A deadlock would occur if the thread" 
			 "blocked is waiting for mutex");
	else if (status == EPERM)
		exit_error("The current thread does not hold a lock on mutex");
	else if (status == ENOMEM)
		exit_error("The process cannot allocate enough memory\n");
	else if (status == EBUSY)
		exit_error("Mutex is locked\n");
}

static void	handle_thread_error(int status, t_codes threadcode)
{
	if (status == 0)
		return ;
	if (status == EAGAIN)
		exit_error("No resource to create another thread\n");
	else if (status == EINVAL && threadcode == CREATE)
		exit_error("The caller doesn't have appropiate perissions\n");
	else if (status == EINVAL && (threadcode == JOIN || threadcode == DETACH))
		exit_error("The value specified is not joinable\n");
	else if (status == ESRCH)
		exit_error("No thread could be found corresponing that"
			 "specified by the given thread ID, thread.\n");
	else if (status == EDEADLK)
		exit_error("A deadlock was detected or the value of"
			 "thread specifies the calling thread.\n");
}

void	mutex_handle(pthread_mutex_t *mutex, t_codes mutexcode)
{
	if (mutexcode == LOCK)
		handle_mutex_error(pthread_mutex_lock(mutex), mutexcode);
	else if (mutexcode == UNLOCK)
		handle_mutex_error(pthread_mutex_unlock(mutex), mutexcode);
	else if (mutexcode == INIT)
		handle_mutex_error(pthread_mutex_init(mutex, NULL), mutexcode);
	else if (mutexcode == DESTROY)
		handle_mutex_error(pthread_mutex_destroy(mutex), mutexcode);
	else
		exit_error("Wrong code for mutex handle\n");
}

void	thread_handle(pthread_t *thread, void *(*foo)(void *), void *data, 
				   t_codes threadcode)
{
	if (threadcode == CREATE)
		handle_thread_error(pthread_create(thread, NULL, foo, data), threadcode);
	else if (threadcode == JOIN)
		handle_thread_error(pthread_join(*thread, NULL), threadcode);
	else if (threadcode == DETACH)
		handle_thread_error(pthread_detach(*thread), threadcode);
	else
		exit_error("Wrong threadcode\n");
}

void	exit_error(char *str)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(RESET, 2);
	exit(EXIT_FAILURE);
}
