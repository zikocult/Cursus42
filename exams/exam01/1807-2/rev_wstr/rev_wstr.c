/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:38:52 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/07/18 22:03:18 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(int c)
{
	write(1, &c, 1);
}

int ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

int count_words(char *str)
{
	int count = 0;
	int i = 0;

	while (str[i])
	{
		while((str[i] == 32 || (str[i] >= 9 && str[i] <= 13)) && str[i])
			i++;
		if (str[i])
			count++;
		while((str[i] != 32 && (str[i] <= 9 || str[i] >= 13)) && str[i])
			i++;
	}
	return (count);
}

int main(int argc, char **argv)
{
	int i;
	int start, end;
	int words;

	if (argc == 2)
	{
		i = ft_strlen(argv[1]) - 1;
		words = count_words(argv[1]);
		while (words > 0)
		{
			while((argv[1][i] == 32 || (argv[1][i] >= 9 && argv[1][i] <= 13)) && i >= 0)
				i--;
			end = i;
			while((argv[1][i] != 32 && (argv[1][i] >= 9 || argv[1][i] <= 13)) && i >= 0)
				i--;
			start = i + 1;
			while(start <= end)
			{
				ft_putchar(argv[1][start]);
				start++;
			}
			words--;
			if (words != 0)
				ft_putchar(' ');
		}
	}
	ft_putchar('\n');
	return (0);
}
