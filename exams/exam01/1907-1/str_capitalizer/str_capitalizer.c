/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:55:20 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/07/19 11:31:28 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void ft_putchar(int c)
{
	write(1, &c, 1);
}

int main(int argc, char **argv)
{
	int i = 1, j;
	int sw;

	if (argc > 1)
	{
		while (i < argc)
		{
			while (argv[i])
			{
				j = 0;
				while(argv[i][j])
				{
					
					while ((argv[i][j] == ' ' || (argv[i][j] >= 9 && argv[i][j] <= 13)) && argv[i][j])
					{
						ft_putchar(argv[i][j]);
						j++;
					}	
					if (argv[i][j])
						sw = 1;
					while ((argv[i][j] != ' ' && (argv[i][j] < 9 || argv[i][j] > 13)) && argv[i][j])
					{
						if (sw == 0)
						{
							if (argv[i][j] >= 'A' && argv[i][j] <= 'Z')
								ft_putchar(argv[i][j] + 32);
							else
								ft_putchar(argv[i][j]);
						}
						else if (sw == 1)
						{
							sw = 0;
							if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
								ft_putchar(argv[i][j] - 32);
							else
								ft_putchar(argv[i][j]);
						}
						j++;
					}	
				}
				ft_putchar('\n');
				i++;
			}
		}
	}
	else if (argc == 1)
		ft_putchar('\n');
	return (0);
}
