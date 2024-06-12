/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:38:33 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/06/12 14:02:49 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		i = (int)len - 1;
		while (i >= 0)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}
/*
int main (void)
{
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int b[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	char c[100] = "Palita";
	char d[100];
    int i = 0;
    
	ft_memmove(&a[2], &a[4], 10);
    while (i++ < 9)
        printf("%i,", a[i]);
    printf("\n");
    i = 0;
    ft_memmove(&b[3], b, 10);
    while (i++ < 9)
        printf("%i,", b[i]);
    printf("\n");
 	
	ft_memmove(d, c, 3);
	printf("\n%s\n", c);
	printf("%s\n", d);
	ft_memmove(&c[2], &c[4], 2);
	printf("%s\n", c);
	return (0);
}*/
