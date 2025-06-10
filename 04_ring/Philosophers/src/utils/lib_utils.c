/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:53:53 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2025/06/02 21:36:37 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"
#include <sys/time.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

bool	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

void	*protect_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (!ret)
		exit_error("🚨 Malloc error\n");
	return (ret);
}

long	gettime(t_time time_code)
{
	struct timeval	time_val;

	if (gettimeofday(&time_val, NULL))
		exit_error("Gettimeofday fail\n");
	if (time_code == SECOND)
		return (time_val.tv_sec + (time_val.tv_usec / 1000000));
	else if (time_code == MILLISECOND)
		return ((time_val.tv_sec * 1000) + (time_val.tv_usec / 1000));
	else if (time_code == MICROSECOND)
		return ((time_val.tv_sec * 1000000) + time_val.tv_usec);
	return (exit_error("Wrong input to gettime own function!"), 1);
}
