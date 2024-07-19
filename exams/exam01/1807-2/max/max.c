/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:52:10 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/07/18 18:05:59 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int max(int* tab, unsigned int len)
{
	int max = 0;
	unsigned int i = 1;

	if (len == 0)
		return (max);
	max = tab[0];
	while (i < len)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

/* int main(void) */
/* { */
/* 	int tab[10] = {2, 30, -14, 25, -100, 43, 12, 4, -321, 2}; */ 
/* 	int mx; */

/* 	mx = max(tab, 10); */
/* 	printf("%i\n", mx); */
/* 	return (0); */
/* } */
