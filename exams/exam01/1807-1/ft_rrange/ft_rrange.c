/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:27:14 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/07/18 10:40:05 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int *ft_rrange(int start, int end)
{
	int i = 0;
	int len;
	int direction;
	int *range;

	if (start >= end)
	{
		len = start - end + 1;
		direction = 1;
	}
	else if (end > start)
	{
		len = end - start + 1;
		direction = 0;
	}
	range = (int *)malloc(len * sizeof(int *));
	if (!range)
		return (NULL);
	if (direction == 1)
	{
		while (i < len)
		{
			range[i] = end + i;
			i++;
		}
	}
	else if (direction == 0)
	{
		while (i < len)
		{
			range[i] = end - i;
			i++;
		}
	}
	return (range);
}

/* int main (void) */
/* { */
/* 	int i = 0; */
/* 	int len; */
/* 	int *range; */
/* 	int start = 0; */
/* 	int end = 0; */
	
/* 	range = ft_rrange(start, end); */
/* 	if (start >= end) */
/* 		len = start - end + 1; */
/* 	else if (end > start) */
/* 		len = end - start + 1; */
/* 	while (i < len) */
/* 	{ */
/* 		printf("[%i] - %i\n", i, range[i]); */
/* 		i++; */
/* 	} */
/* 	free(range); */
/* 	return (0); */
/* } */
