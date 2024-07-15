/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:36:28 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/07/15 15:02:12 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int main (int argc, char **argv)
{
	int	i = 0;

	if (argc == 2)
	{
		while (argv[1][i])
		{
			if ((argv[1][i] >= 'A' && argv[1][i] <= 'Z') 
					||(argv[1][i] >= 'a' && argv[1][i] <= 'z'))
			{
				if (argv[1][i] != 'z' && argv[1][i] != 'Z')
					ft_putchar(argv[1][i] + 1);
				else if (argv[1][i] == 'z')
					ft_putchar('a');
				else if (argv[1][i] == 'Z')
					ft_putchar('A');
			}	
			else
				ft_putchar(argv[1][i]);
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
