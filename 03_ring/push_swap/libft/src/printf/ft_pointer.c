/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:21:43 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/07/30 12:35:10 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	ft_hexa_point_pf(unsigned long int nb, int *count)
{
	if (nb >= 16)
	{
		ft_hexa_point_pf(nb / 16, count);
		ft_hexa_point_pf(nb % 16, count);
	}
	else
	{
		if (nb <= 9 && *count != -1)
			ft_putchar_pf((nb + '0'), count);
		else if (*count != -1)
			ft_putchar_pf((nb - 10 + 'a'), count);
	}
}

void	ft_pointer_pf(void *pointer, int *count)
{
	if (!pointer && *count != -1)
	{
		ft_putstr_pf("(nil)", count);
		return ;
	}
	if (*count != -1)
		ft_putstr_pf("0x", count);
	if (*count != -1)
		ft_hexa_point_pf((unsigned long int)pointer, count);
}
