/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 10:55:05 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/07/16 11:12:02 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(int c)
{
	write (1, &c, 1);
}

int main(int argc, char **argv)
{
	int repeat;
	int i = 0;

	if (argc == 2)
	{
		while (argv[1][i])
		{
			repeat = 1;
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
				repeat = (int)argv[1][i] - 'a' + 1;
			else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				repeat = (int)argv[1][i] - 'A' + 1;
			while (repeat > 0)
			{
				ft_putchar(argv[1][i]);
				repeat--;
			}
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
