/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:11:32 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/07/19 16:26:01 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void ft_putchar(int c)
{
	write(1, &c, 1);
}

int count_words(char *str)
{
	int i = 0;
	int count = 0;

	while(str[i])
	{
		while ((str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)) && str[i])
			i++;
		if (str[i])
			count++;
		while((str[i] != ' ' && (str[i] < 9 || str[i] > 13)) && str[i])
			i++;
	}
	return (count);
}

int main(int argc, char **argv)
{
	int i = 0;
	int words;

	if(argc == 2)
	{
		words = count_words(argv[1]);
		while (argv[1][i])
		{
			while ((argv[1][i] == ' ' || (argv[1][i] >= 9 && argv[1][i] <= 13)) && argv[1][i])
				i++;
			while((argv[1][i] != ' ' && (argv[1][i] < 9 || argv[1][i] > 13)) && argv[1][i])
			{
				ft_putchar(argv[1][i]);
				i++;
			}
			words--;
			if (words > 0)
			{
				ft_putchar(' ');
				ft_putchar(' ');
				ft_putchar(' ');
			}
		}
	}
	ft_putchar('\n');
	return (0);
}
