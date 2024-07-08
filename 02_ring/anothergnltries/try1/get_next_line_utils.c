/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:58:41 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/07/07 11:39:55 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *)malloc((ft_strlen(s)) + 1 * sizeof(char));
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

char	*ft_strjoin(char *gnl_temp, char *str_tmp, char *temp, int *control)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)malloc(ft_strlen(gnl_temp)
			+ ft_strlen(str_tmp) + 1 * sizeof(char));
	if (!str)
		return (NULL);
	while (gnl_temp[i] != '\0' && gnl_temp[i] != '\0' && gnl_temp[i] != 0)
	{
		str[i] = gnl_temp[i];
		i++;
	}
	if (gnl_temp[i] == '\0')
	{
		temp = (char *)malloc(ft_strlen(&gnl_temp[i + 1] + 1 * sizeof(char)));
		if (!temp)
			return (NULL);
		temp = ft_strdup(&gnl_temp[i + 1]);
		*control = 1;
	}
	while (str_tmp[j] != '\0')
		str[i++] = str_tmp[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin2(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char));
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
