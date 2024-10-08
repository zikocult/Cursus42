/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:11:49 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/06/07 14:53:22 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int main (void)
{
	int *test, min, max, i;

	min = -10;
	max = 30;
	i = 0;
	
	test = ft_range(min, max);
	ft_foreach(test, max - min - 1, &ft_putnbr);
	
	i = 0;
	printf("\n");
	while (i < max - min)
	{
		printf("%i\n", test[i]);
		i++;
	}
	
	free (test);
	return (0);
}
