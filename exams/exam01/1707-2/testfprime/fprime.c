/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:57:20 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/07/18 15:38:51 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int ft_next_prime(int prime, int nbr)
{
	int i;
	int sw;

	while (prime <= nbr)
	{
		sw = 0;
		prime = prime + 1;
		if (prime >= nbr / 2)
			return (nbr);
		i = 3;
		while (i < prime && sw == 0)
		{
			if (prime % i == 0)
				sw = 1;
			i += 2;
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
