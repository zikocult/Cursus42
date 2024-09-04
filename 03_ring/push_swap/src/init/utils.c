/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 08:05:15 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/09/05 00:28:00 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

bool	check_alpha(const char *ptr)
{
	int		i;
	bool	check;

	i = 0;
	check = false;
	if (!ptr[i])
		return (false);
	while (ptr[i] == ' ' || (ptr[i] >= 9 && ptr[i] <= 13))
		i++;
	if ((ptr[i] == '+') || (ptr[i] == '-'))
		i++;
	while (ptr[i] != '\0' && ptr[i] >= '0' && ptr[i] <= '9')
	{
		check = true;
		i++;
	}
	while (ptr[i] == ' ' || (ptr[i] >= 9 && ptr[i] <= 13))
		i++;
	if (ptr[i] != '\0')
		return (false);
	return (check);
}

long	ft_atol(const char *ptr)
{
	int		i;
	int		neg;
	long	result;

	i = 0;
	neg = 1;
	result = 0;
	while (ptr[i] == ' ' || (ptr[i] >= 9 && ptr[i] <= 13))
		i++;
	if (ptr[i] == '+' || ptr[i] == '-')
	{
		if (ptr[i] == '-')
			neg = -1;
		i++;
	}
	while (ptr[i] != '\0' && ptr[i] >= '0' && ptr[i] <= '9')
	{
		result = (result * 10) + (ptr[i] - '0');
		i++;
	}
	return (result * neg);
}
