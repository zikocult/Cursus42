/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:55:05 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/06/13 12:25:17 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *) dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
/*
int main (void)
{
	int a[100] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	char b[100] = "Palita";
	char c[100];
	int i = 0;
	printf("boniato\n%s\n", c);
	while (i++ < 9)
		printf("%i,", a[i]);
	printf("\n");
	ft_memcpy(&a[2], &a[4], 10);
	i = 0;
	while (i++ < 9)
		printf("%i,", a[i]);
	ft_memcpy(c, b, 3);
	printf("\n%s\n", b);
	printf("%s\n", c);
	ft_memcpy(&b[2], &b[4], 10);
	printf("%s\n", b);
	return (0);
}*/
