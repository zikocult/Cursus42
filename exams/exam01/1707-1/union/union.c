/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:04:21 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/07/17 11:16:51 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar (int c)
{
	write(1, &c, 1);
}

int main (int argc, char **argv)
{
	int i = 0;
	int j = 0;
	int control = 0;

	if (argc == 3)
	{
		while (argv[1][i])
		{
			control = 0;
			j = 0;
			while (j < i && control == 0)
			{
				if (argv[1][i] == argv[1][j])
					control = 1;
				j++;
			}
			if (control == 0)
				ft_putchar(argv[1][i]);
			i++;
		}
		i = 0;
		while (argv[2][i])
		{
			control = 0;
			j = 0;
			while (argv[1][j] && control == 0)
			{
				if (argv[2][i] == argv[1][j])
					control = 1;
				j++;
			}
			j = 0;
			while (j < i && control == 0)
			{
				if (argv[2][i] == argv[2][j])
					control = 1;
				j++;
			}
			if (control == 0)
				ft_putchar(argv[2][i]);
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
