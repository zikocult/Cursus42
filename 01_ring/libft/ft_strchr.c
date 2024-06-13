/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:35:19 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/06/13 21:58:44 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != '\0')
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if (*str == (char)c)
		return (str);
	return (NULL);
}
/*
int main()
{
	char a[50] = "patata";
	char b[50] = "patada";
	char c[50] = "peteda";
	printf("%s\n", ft_strchr(a, 'a'));
	printf("%s\n", ft_strchr(b, 'd'));
	printf("%s\n", ft_strchr(c, 'z'));
}*/
