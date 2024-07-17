/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:14:40 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/07/16 11:21:39 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(int c)
{
	write(1, &c, 1);
}

int main(int argc, char **argv)
{
	int i = 0;
	if (argc == 2)
	{
		while(argv[1][i])
		{
			if (i > 1)
			{
				if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				{
					ft_putchar('_');
					ft_putchar(argv[1][i] + 32);
				}
				else
					ft_putchar(argv[1][i]);
			}
			else
					ft_putchar(argv[1][i]);
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
