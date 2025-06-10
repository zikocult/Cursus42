/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:29:23 by gbaruls-          #+#    #+#             */
/*   Updated: 2025/06/02 21:36:32 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// USED LIBRARIES
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>
# include <limits.h>
# include <errno.h>

// CUSTOM DEFINES
# define RESET			"\033[0m"
# define BLACK			"\033[30m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define MAGENTA		"\033[35m"
# define CYAN			"\033[36m"
# define WHITE			"\033[37m"

// STRUCTURES AND ENUMS
typedef struct s_table	t_table;

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				fork_id;
}	t_fork;

typedef struct s_philo
{
	int			id;
	int			meals_counter;
	bool		full;
	long		last_meal_time;
	t_fork		*first_fork;
	t_fork		*second_fork;
	pthread_t	thread_id;
	t_table		*table;
}	t_philo;

struct s_table
{
	int				philo_nbr;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				nbr_limit_meals;
	long			start_simulation;
	bool			end_simulation;
	bool			all_thread;
	pthread_mutex_t	table_mutex;
	t_fork	*forks;
	t_philo	*philos;
};

typedef enum e_codes
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}	t_codes;

typedef enum e_time
{
	SECOND,
	MILLISECOND,
	MICROSECOND,
}	t_time;


// PROTOTYPES
// Utils
void	ft_putstr_fd(char *s, int fd);
bool	ft_isdigit(char c);
void	*protect_malloc(size_t bytes);
void	exit_error(char *str);
void	thread_handle(pthread_t *thread, void *(*foo)(void *), void *data,
			t_codes threadcode);
void	mutex_handle(pthread_mutex_t *mutex, t_codes mutexcode);
long	gettime(t_time time_code);

// Parsing
void	parse_input(t_table *table, char **argv);
void	init_tables(t_table *table);

// Action
void	action_begin(t_table *table);

// Synchro
void	wait_all_threads(t_table *table);

//No race functions
void	set_bool(pthread_mutex_t *mutex, bool *dest, bool value);
void	set_long(pthread_mutex_t *mutex, long *dest, long value);
bool	get_bool(pthread_mutex_t *mutex, bool *value);
bool	get_long(pthread_mutex_t *mutex, long *value);
bool	simulation_finished(t_table *table);

#endif
