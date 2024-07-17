/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:00:21 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/07/17 17:01:53 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(int c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	int i = 0;

	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}
