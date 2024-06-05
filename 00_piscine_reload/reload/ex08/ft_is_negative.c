/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:51:48 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/06/05 17:51:51 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_is_negative(int n)
{
	if (n < 0)
		ft_putchar('N');
	else
		ft_putchar('P');
}
/*int main(void){
	ft_is_negative(0);
	ft_putchar('\n');
	ft_is_negative(-10);
	ft_putchar('\n');
	ft_is_negative(10);
	ft_putchar('\n');
	ft_is_negative(34);
	ft_putchar('\n');
	ft_is_negative(-2);
	ft_putchar('\n');
	ft_is_negative(4);
	ft_putchar('\n');
	ft_is_negative(-1000);
	ft_putchar('\n');
}*/
