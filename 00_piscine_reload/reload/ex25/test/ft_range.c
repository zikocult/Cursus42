/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:33:56 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/06/07 12:48:25 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h" 

int	*ft_range(int min, int max)
{
	int	*result;
	int	i;

	if (min >= max)
		return (NULL);
	result = (int *)malloc(sizeof(int) * (max - min));
	if (!result)
		return (NULL);
	i = 0;
	while (min < max)
		result[i++] = min++;
	return (result);
}
