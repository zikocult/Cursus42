/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:07:05 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/07/18 18:35:13 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void ft_putchar(int c)
{
	write(1, &c, 1);
}

int ft_atoi(char *str)
{
	int i = 0;
	int result = 0;

	while((str[i] == 32 || (str[i] >= 9 && str[i] <= 13)) && str[i])
		i++;
	if(str[i] == '-')
		return (-1);
	if(str[i] == '+')
		i++;
	while((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result);
}

void ft_putnbr(int nbr)
{
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		nbr = nbr % 10;
	}
	if (nbr < 10)
		ft_putchar(nbr + '0');
}

int main (int argc, char **argv)
{
	int nbr;
	int i = 1;


	if (argc == 2)
	{
		nbr = ft_atoi(argv[1]);
		if (nbr == -1)
		{
			ft_putchar('\n');
			return (1);
		}
		while (i <= 9)
		{
			ft_putnbr(i);
			write(1, " x ", 3);
			ft_putnbr(nbr);
			write(1, " = ", 3);
			ft_putnbr(i * nbr);
			ft_putchar('\n');
			i++;
		}
	}
	else
		ft_putchar('\n');
	return (0);
}
