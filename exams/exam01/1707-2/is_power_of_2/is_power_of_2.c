/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:04:12 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/07/17 17:19:12 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_power_of_2(unsigned int n)
{
	unsigned long power = 2;

	if (n == 1)
		return (1);
	while (power < n)
		power = power * 2;
	if (power == n)
		return (1);
	return (0);
}

/* int main (void) */
/* { */
/* 	printf("Result %d\n", is_power_of_2(2)); */
/* 	printf("Result %d\n", is_power_of_2(4)); */
/* 	printf("Result %d\n", is_power_of_2(-3)); */
/* 	printf("Result %d\n", is_power_of_2(0)); */
/* 	printf("Result %d\n", is_power_of_2(1)); */
/* 	printf("Result %d\n", is_power_of_2(62)); */
/* } */
