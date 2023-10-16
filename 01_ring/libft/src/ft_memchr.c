/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ZikoCult <ZikoCult>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:47:11 by ZikoCult          #+#    #+#             */
/*   Updated: 2023/10/16 23:25:08 by ZikoCult         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i)
	{
		if ((*(unsigned char *)(s + i)) == ((unsigned char)c))
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
