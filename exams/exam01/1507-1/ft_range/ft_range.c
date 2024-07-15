/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:25:05 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/07/15 16:04:25 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int     *ft_range(int start, int end)
{
	int i = 0;
	int len;
	int *range;
	int direction;
	
	if (start >= end)
	{
		len = start - end + 1;
		direction = 1;
	}
	else
	{
		len = end - start + 1;
		direction = 0;
	}
	range = (int *)malloc(len * sizeof(int));
	if (!range)
		return (NULL);
	while (i < len)
	{
		if (direction == 0)
			range[i] = start + i;
		if (direction == 1)
			range[len - i - 1] = end + i;
		i++;
	}
	return (range);
}

/* int main (void) */
/* { */
/* 	int	*range; */
/* 	int i = 0; */
/* 	int start = 1; */
/* 	int end = 1; */
/* 	int len; */

/* 	if (start >= end) */
/* 		len = start - end + 1; */
/* 	else */
/* 		len = end - start + 1; */
/* 	range = ft_range(start, end); */
/* 	if (!range) */
/* 		return (1); */
/* 	while (i < len) */
/* 	{ */
/* 		printf("[%i] - %i\n", i + 1, range[i]); */
/* 		i++; */
/* 	} */
/* 	free (range); */
/* 	return (0); */
/* } */
