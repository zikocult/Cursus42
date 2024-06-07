/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:41:54 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/06/06 12:51:02 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}
/*
int main (void)
{
	char test[50] = "patata";
	ft_putstr(test);
	ft_putchar('\n');
	char test2[50] = "";
	ft_putstr(test2);
	ft_putchar('\n');
	char test3[50] = " ";
	ft_putstr(test3);
	ft_putchar('\n');
	char test4[50] = "i love code";
	ft_putstr(test4);
	ft_putchar('\n');
}*/
