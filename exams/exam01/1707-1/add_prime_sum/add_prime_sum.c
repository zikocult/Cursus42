/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:24:00 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/07/17 12:41:28 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void ft_putchar(int c)
{
	write(1, &c, 1);
}

void putnbr(int lnb)
{
	if (lnb >= 10)
	{
		putnbr(lnb / 10);
		lnb = lnb % 10;
	}
	if (lnb < 10)
		ft_putchar(lnb + '0');
}

int ft_atoi(char *str)
{
	int i = 0;
	int result = 0;
	if (str[i] == '-')
		return (-1);
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result);
}

int main (int argc, char **argv)
{
	int nb;
	int i, j;
	int prime;
	int result = 0;

	if (argc == 2)
	{
		nb = ft_atoi(argv[1]);
		if (nb < 0)
		{
			ft_putchar('0');
			ft_putchar('\n');
			return (1);
		}
		i = 2;
		if (nb > 2)
		{
			while (i <= nb)
			{
				j = 2;
				prime = 0;
				while (j < i && prime == 0)
				{
					if (i % j == 0)
						prime = 1;
					j++;
				}
				if (prime == 0)
					result = result + i;
				i++;
			}
		}
		else if (nb == 2)
			result = 2;
		putnbr(result);
	}
	else
		ft_putchar('0');
	ft_putchar('\n');
	return (0);
}
