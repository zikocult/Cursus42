/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:50:01 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/06/14 17:47:32 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*ptr;

	i = 0;
	len = ft_strlen(s);
	ptr = (char *)malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	while (s[i])
	{
		ptr[i] = (char)s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*
int main (int argc, char **argv)
{
	if (argc == 2)
	{
		char *ptr = ft_strdup(argv[1]);
		printf("%s\n", ptr);
		free(ptr);
	}
}*/
