/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:57:20 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/07/17 18:34:46 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int ft_next_prime(int prime, int nbr)
{
	int i = 2;
	int j;
	int sw = 0;

	while (i <= nbr && sw == 0)
	{
		prime = prime + 1;
		if (prime >= nbr / 2)
			return (nbr);
		j = 2;
		while (j < prime && sw == 0)
		{
			if (prime % j == 0)
				sw = 1;
			j++;
		}
		if (sw == 0)
			return (prime);
	}
	return (prime);
}

int main (int argc, char **argv)
{
	int arg;
	int next_prime = 2;

	if (argc == 2)
	{
		arg = atoi(argv[1]);
		if (arg == 1)
			printf("1");
		while (arg / next_prime > 0)
		{
			if (arg % next_prime != 0)
				next_prime = ft_next_prime(next_prime, arg);
			else if (arg % next_prime == 0)
			{
				if (next_prime != arg)
					printf("%i*", next_prime);
				else
					printf("%i", next_prime);
				arg = arg / next_prime;
			}
		}
	}
	printf("\n");
	return (0);
}
