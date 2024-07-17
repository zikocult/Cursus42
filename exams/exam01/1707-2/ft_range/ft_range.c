/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:20:51 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/07/17 17:46:12 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int len, direction;
	int *range;
	int i = 0;

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
	if (direction == 1)
	{
		while (i < len)
		{
			range[i] = start - i;
			i++;
		}
	}
	else if (direction == 0)
	{
		while (i < len)
		{
			range[i] = start + i;
			i++;
		}
	}
	return (range);
}

/* int main(void) */
/* { */
/* 	int start = 0; */
/* 	int end = 0; */
/* 	int *range; */
/* 	int i = 0; */
/* 	int len; */

/* 	range = (ft_range(start, end)); */
/* 	if (start >= end) */
/* 		len = start - end + 1; */
/* 	else if (end > start) */
/* 		len = end - start + 1; */
/* 	while (i < len) */
/* 	{ */
/* 		printf("%i\n", range[i]); */
/* 		i++; */
/* 	} */
/* 	free (range); */
/* 	return (0); */
/* } */
