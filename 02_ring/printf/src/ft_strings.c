/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:38:33 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/07/03 13:18:36 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <unistd.h>

void	ft_putchar_pf(char c, int *count)
{
	int	i;

	i = write(1, &c, 1);
	if (i == -1)
		*count = -1;
	else
		*count = *count + 1;
}

void	ft_putstr_pf(char *str, int *count)
{
	int	i;

	i = 0;
	if (!str)
		ft_putstr_pf("(null)", count);
	else
	{
		while (str[i] && *count != -1)
		{
			ft_putchar_pf(str[i], count);
			i++;
		}
	}
}
