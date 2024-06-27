/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:26:19 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/06/27 18:26:54 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_case_pf(va_list args, const char format, int *count)
{
	if (format == 'c')
		ft_putchar_pf(va_arg(args, int), count);
	else if (format == 's')
		ft_putstr_pf(va_arg(args, char *), count);
	else if (format == '%')
		ft_putchar_pf('%', count);
	else if (format == 'd' || format == 'i')
		ft_nbr_pf(va_arg(args, int), count);
	else if (format == 'u')
		ft_unnbr_pf(va_arg(args, unsigned int), count);
	else if (format == 'x')
		ft_hexa_pf(va_arg(args, unsigned int), "0123456789abcdef", count);
	else if (format == 'X')
		ft_hexa_pf(va_arg(args, unsigned int), "0123456789ABCDEF", count);
	else if (format == 'p')
		ft_pointer_pf(va_arg(args, void *), count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	count = 0;
	i = 0;
	va_start(args, str);
	while (str[i] && count != -1)
	{
		if (str[i] == '%')
		{
			ft_case_pf(args, str[i + 1], &count);
			i++;
		}
		else
			ft_putchar_pf(str[i], &count);
		i++;
	}
	va_end(args);
	return (count);
}
