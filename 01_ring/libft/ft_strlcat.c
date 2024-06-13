/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:49:21 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/06/13 11:10:04 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
/*
int main()
{
	char a[10] = "patata";
	char b[50] = "qeveve";
	int ret = ft_strlcat(b, a, 1000);
	printf("Ret = %i - %s\n", ret, b);
	char c[10] = "boniato";
	char d[10] = "qeveve";
	ret = ft_strlcat(d, c, 0);
	printf("Ret = %i - %s\n", ret, d);
	char e[10] = "mor";
	char f[10] = "cande";
	ret = ft_strlcat(f, e, 5);
	printf("Ret = %i - %s\n", ret, f);
}*/
