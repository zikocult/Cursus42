/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:51:58 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/06/20 16:53:16 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_minint(char *str)
{
	str[0] = '-';
	str[1] = '2';
	return (147483648);
}

static int	ft_intlen(int n)
{
	int	count;

	count = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n / 10 > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;

	i = ft_intlen(n);
	str = (char *)ft_calloc(i + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (n == -2147483648)
		n = ft_minint(str);
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n / 10 >= 0)
	{
		str[i - 1] = (n % 10) + '0';
		i--;
		if (n / 10 == 0)
			return (str);
		n = n / 10;
	}
	return (str);
}
