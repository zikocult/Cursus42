/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:14:28 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/06/13 13:21:45 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if(((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return ((void *)(s1 + i) - (void *)(s2 + i));
		i++;
	}
	return ((void *)(s1 + i) - (void *)(s2 + i));
}
