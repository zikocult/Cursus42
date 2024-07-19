/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:35:05 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/07/19 12:09:38 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(int c)
{
	write(1, &c, 1);
}

int count_words(char *str)
{
	int count = 0;
	int i = 0;
	
	while (str[i])
	{
		while ((str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)) && str[i])
			i++;
		if (str[i])
			count++;
		while ((str[i] != ' ' && (str[i] < 9 || str[i] > 13)) && str[i])
			i++;
	}
	return (count);
}

int main(int argc, char **argv)
{
	int i = 0;
	int sw = 0;
	int words;

	if (argc > 1)
	{
		words = count_words(argv[1]);
		while (argv[1][i])
		{
			while ((argv[1][i] == ' ' || (argv[1][i] >= 9 && argv[1][i] <= 13)) && argv[1][i])
				i++;
			if (words > 1)
			{
				if (sw == 0)
				{
					while ((argv[1][i] != ' ' && (argv[1][i] < 9 || argv[1][i] > 13)) && argv[1][i])
						i++;
					sw = 1;
				}
				else if (sw == 1 && argv[1][i])
				{
					while ((argv[1][i] != ' ' && (argv[1][i] < 9 || argv[1][i] > 13)) && argv[1][i])
					{
						ft_putchar(argv[1][i]);
						i++;
					}
					ft_putchar(' ');
				}
			}
			else if (words == 1)
			{
				while ((argv[1][i] != ' ' && (argv[1][i] < 9 || argv[1][i] > 13)) && argv[1][i])
				{
					ft_putchar(argv[1][i]);
					i++;
				}
			}
		}
		i = 0;
		if (words > 1)
		{
			while ((argv[1][i] == ' ' || (argv[1][i] >= 9 && argv[1][i] <= 13)) && argv[1][i])
				i++;
			while ((argv[1][i] != ' ' && (argv[1][i] < 9 || argv[1][i] > 13)) && argv[1][i])
			{
				ft_putchar(argv[1][i]);
				i++;
			}
		}
	}
	ft_putchar('\n');
}
