/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:38:09 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/07/12 17:54:20 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main (int argc, char **argv)
{
	int	i, j, sw;

	i = 1;
	if (argc != 3)
		return (1);
	else
	{
		write(1, &argv[1][0], 1);
		while (argv[1][i] != '\0')
		{
			j = 0;
			while (argv[1][j] && i > j + 1)
			{
				if (argv[1][j] == argv[1][i])
					break ;
				j++;
			}
			if (argv[1][i] == argv[1][j])
				i++;
			else
			{
				write(1, &argv[1][i], 1);
				i++;
			}
		}
		i = 0;
		while (argv[2][i] != '\0')
		{
			j = 0;
			sw = 0;
			while (argv[1][j] && sw == 0)
			{
				if (argv[1][j] == argv[2][i])
					sw = 1;	
				j++;
			}
			j = 0;
			while (i < j && sw == 0)
			{
				if (argv[2][j] == argv[2][i])
					sw = 1;
				j++;
			}
			if (sw == 1)
				i++;
			else
			{
				write(1, &argv[2][i], 1);
				i++;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
