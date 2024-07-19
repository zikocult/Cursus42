/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:57:13 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/07/19 16:07:50 by gbaruls-         ###   ########.fr       */
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
			if(argv[1][i] >= 'a' && argv[1][i] <= 'm')
				ft_putchar('a' - argv[1][i] + 'z');
			else if(argv[1][i] >= 'A' && argv[1][i] <= 'M')
				ft_putchar('A' - argv[1][i] + 'Z');
			else if(argv[1][i] >= 'n' && argv[1][i] <= 'z')
				ft_putchar('z' - argv[1][i] + 'a');
			else if(argv[1][i] >= 'N' && argv[1][i] <= 'Z')
				ft_putchar('Z' - argv[1][i] + 'A');
			else
				ft_putchar(argv[1][i]);
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
