/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:34:04 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/07/08 20:02:34 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	if (*s == (char)c)
		return (s);
	return (0);
}

char	*copy_str(char *gnl_str, char *buff, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (gnl_str[i] != '\0')
	{
		str[i] = gnl_str[i];
		i++;
	}
	while (buff[j] != '\0')
	{
		str[i] = buff[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *gnl_str, char *buff)
{
	char	*str;

	if (!gnl_str)
	{
		gnl_str = (char *)malloc(1 * sizeof(char));
		if (!gnl_str)
			return (NULL);
		gnl_str[0] = '\0';
	}
	if (!gnl_str || !buff)
		return (NULL);
	str = (char *)malloc(((ft_strlen(gnl_str) + ft_strlen(buff)) + 1)
			* sizeof(char));
	if (!str)
		return (NULL);
	str = copy_str(gnl_str, buff, str);
	free(gnl_str);
	return (str);
}
