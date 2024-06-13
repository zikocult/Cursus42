/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:40:07 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/06/13 13:10:16 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
/*
int main (int argc, char **argv)
{
	char *test;
	char *test2;
	if (argc == 3)
	{
		test = ft_memchr(argv[1], argv[2][0], 4);
		test2 = memchr(argv[1], argv[2][0], 4);
		printf("test1 - %s\ntest2 - %s\n", test, test2);
	}
	return (0);
}*/
