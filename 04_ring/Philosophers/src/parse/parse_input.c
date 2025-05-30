/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:40:58 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2025/05/30 18:46:29 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/philo.h"

static char	*init_value(char *str)
{
	int		len;
	char	*number;

	len = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		exit_error("🚨 Only positive number for the input 🚨\n");
	if (!ft_isdigit(*str))
		exit_error("🚨 The input is not a correct number 🚨\n");
	number = str;
	while (ft_isdigit(*str++))
		len++;
	if (len > 10)
		exit_error("🚨 The value exceed the INT_MAX value 🚨\n");
	return (number);
}

static long	ft_atol(char *str)
{
	long	num;

	num = 0;
	str = init_value(str);
	while (ft_isdigit(*str))
	{
		num = (num * 10) + (*str - 48); 
		str++;
	}
	if (num > INT_MAX)
		exit_error("🚨 The value exceed the INT_MAX value 🚨\n");
	if (num == 0)
		exit_error("🚨 No philosophers to eat, sleep, think or die 🚨\n");
	return (num);
}

void	parse_input(t_table *table, char **argv)
{
	table->philo_nbr = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]) * 1000;
	table->time_to_eat = ft_atol(argv[3]) * 1000;
	table->time_to_sleep = ft_atol(argv[4]) * 1000;
	if (argv[5])
		table->nbr_limit_meals = ft_atol(argv[5]);
	else
		table->nbr_limit_meals = -1;
}
