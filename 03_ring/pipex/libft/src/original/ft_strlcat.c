/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:49:21 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/06/20 19:26:46 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	i = 0;
	len = ft_strlen(dst);
	if (size != 0)
	{
		while (src[i] != '\0' && len + 1 < size)
		{
			dst[len] = src[i];
			i++;
			len++;
		}
		dst[len] = '\0';
	}
	return (ft_strlen(dst) + ft_strlen(&src[i]));
}
