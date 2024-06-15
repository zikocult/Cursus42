/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:20:24 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/06/15 12:48:54 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	return (str);
}
/*
int main (int argc, char **argv)
{
	if (argc == 3)
	{
		char *str;
		char *str2;
		str = ft_strjoin(argv[1], argv[2]);
		str2 = ft_strjoin(argv[2], argv[1]);
		printf("1 %s\n2 %s\n", str, str2);
		free (str);
		free (str2);
	}
}*/
