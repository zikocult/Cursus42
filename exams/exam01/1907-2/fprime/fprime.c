/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:28:52 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/07/19 16:49:11 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int next_prime(int arg, int prime)
{
	int sw = 0;
	int j;

	while (arg / 2 > prime)
	{
		sw = 0;
		j = 2;
		prime++;
		while (j < prime && sw == 0)
		{
			if (prime % j == 0)
				sw = 1;
			j ++;
		}
		if (sw == 0)
			return (prime);
	}
	if (arg / 2 <= prime)
		return (arg);
	return (prime);
}

int main(int argc, char **argv)
{
	int arg;
	int prime = 2;

	if (argc == 2)
	{
		arg = atoi(argv[1]);
		if (arg == 1)
		{
			printf("1\n" );
			return (0);
		}
		while (arg / prime > 0)
		{
			if (arg % prime != 0)
				prime = next_prime(arg, prime);
			if (arg % prime == 0)
			{
				if(prime >= arg)
					printf("%i", prime);
				else if (prime < arg)
					printf("%i*", prime);
				arg = arg / prime;
			}
		}
	}
	printf("\n");
	return (0);
}
