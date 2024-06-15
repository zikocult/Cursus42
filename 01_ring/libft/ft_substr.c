/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:04:22 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/06/15 11:10:24 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	while ((char)s[start + i] != '\0' && i < len)
	{
		str[i] = (char)s[i + start];
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
		char *ptr2 = ft_substr("", 10, 3);
		printf("%s\n", ptr2);
		free(ptr2);
	}
}*/
