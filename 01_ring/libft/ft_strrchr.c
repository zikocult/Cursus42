/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:52:17 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/06/12 19:17:08 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = ft_strlen(str);
	while (i > 0)
	{
		if (str[i] == c)
			return (&str[i]);
		i--;
	}
	return (NULL);
}
/*
int main()
{
	char a[50] = "patata";
	char b[50] = "patada";
	char c[50] = "peteda";
	printf("%s\n", ft_strrchr(a, 'a'));
	printf("%s\n", ft_strrchr(b, 't'));
	printf("%s\n", ft_strrchr(c, 'e'));
}*/
