/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:04:22 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/06/14 18:18:48 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	while ((char)s[start + (int)i] != '\0' && i < len)
	{
		str[i] = (char)s[(int)i + start];
		i++;
	}
	return (str);
}
/*
int main (int argc, char **argv)
{
	if (argc >= 2)
	{
		char *ptr = ft_substr(argv[1], 3, 3);
		printf("%s\n", ptr);
		free(ptr);
	}
}*/
