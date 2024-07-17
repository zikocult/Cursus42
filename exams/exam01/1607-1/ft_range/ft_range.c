/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:23:49 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/07/16 11:40:47 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int *ft_range(int start, int end)
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
	else if (end > start)
	{
		len = end - start + 1;
		direction = 0;
	}
	range = (int *)malloc(len * sizeof(int));
	if (!range)
		return (NULL);
	while (i < len)
	{
		if (direction == 1)
			range[i] = start - i;
		if (direction == 0)
			range[i] = start + i;
		i++;
	}
	return (range);
}
/*
int main (void)
{
	int i = 0;
	int start = 10;
	int end = 10;
	int len;
	int *range;

	if (start >= end)
		len = start - end + 1;
	else if (end > start)
		len = end - start + 1;
	range = ft_range(start, end);
	while (len > i)
	{
		printf("[%d] - %d\n", i, range[i]);
		i++;
	}
	free(range);
	return (0);
}*/
