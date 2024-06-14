/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:49:14 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/06/14 14:35:14 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!s2 || !s1)
		return ((char *)s1);
	while (s1[i] != '\0' && i < len)
	{
		if (s1[i] == s2[0])
		{
			j = 0;
			while (s1[i + j] == s2[j] && s1[i + j] != '\0')
			{
				if (s2[j + 1] == '\0')
					return ((char *)s1 + i);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
/*
int main(int argc, char **argv)
{
	if (argc == 3)
	{
		printf("%s\n", ft_strnstr(argv[1], argv[2], 100));
		printf("%s\n", ft_strnstr(argv[1], NULL, 100));
	
		char *a = ft_strnstr("patata melonera", argv[2], 100);
		if (a == NULL)
			printf("NULL\n");
		else
			printf("%s\n", a);
		
		char *b = ft_strnstr(NULL, argv[2], 100);
		if (b == NULL)
			printf("NULL\n");
		else
			printf("%s\n", b);
	}
}*/
