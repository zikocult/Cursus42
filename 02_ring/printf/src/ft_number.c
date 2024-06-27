/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:52:36 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/06/27 13:19:43 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_nbr_pf(int nbr, int *count)
{
	if (nbr == -2147483648 && *count != -1)
	{
		ft_putstr_pf("-2147483648", count);
		return ;
	}
	if (nbr < 0 && *count != -1)
	{
		ft_putchar_pf('-', count);
		ft_nbr_pf(nbr * -1, count);
	}
	else if (*count != -1)
	{
		if (nbr > 9)
			ft_nbr_pf(nbr / 10, count);
		if (*count != -1)
			ft_putchar_pf(nbr % 10 + '0', count);
	}
}

void	ft_unnbr_pf(unsigned int nbr, int *count)
{
	if (nbr > 9)
		ft_unnbr_pf(nbr / 10, count);
	if (*count != -1)
		ft_putchar_pf(nbr % 10 + '0', count);
}

void	ft_hexa_pf(unsigned long int num, char *base, int *count)
{
	unsigned int	nb;

	nb = num;
	if (nb < 16 && *count != -1)
		ft_putchar_pf(base[nb], count);
	if (nb >= 16)
	{
		ft_hexa_pf(nb / 16, base, count);
		ft_hexa_pf(nb % 16, base, count);
	}
}
