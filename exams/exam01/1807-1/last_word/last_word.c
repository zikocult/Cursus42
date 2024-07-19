/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:01:52 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/07/18 10:24:26 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(int c)
{
	write (1, &c, 1);
}

int main(int argc, char **argv)
{
	int i = 0;
	int start = 0;

	if (argc == 2)
	{
		while (argv[1][i])
		{
			while ((argv[1][i] == ' ' || argv[1][i] == 9 || argv[1][i] == 10 || argv[1][i] == 11) && argv[1][i])
				i++;
			if (argv[1][i])
				start = i;
			while (argv[1][i] != ' ' && argv[1][i] != 9 && argv[1][i] != 10 && argv[1][i] != 11 && argv[1][i])
				i++;
		}
		if (argv[1][start])
		{
			while (argv[1][start] != ' ' && argv[1][start] != 9 && argv[1][start] != 10 && argv[1][start] != 11 && argv[1][start])
			{
				ft_putchar(argv[1][start]);
				start++;
			}
		}
	}
	ft_putchar('\n');
	return (0);
}
