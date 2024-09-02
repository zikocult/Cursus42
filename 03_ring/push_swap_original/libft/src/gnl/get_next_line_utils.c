/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 20:08:08 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/07/30 13:05:38 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

size_t	ft_strlen_gnl(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)&s[ft_strlen_gnl(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*join_dup(char *gnl, char *buff)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	len = ft_strlen_gnl(gnl) + ft_strlen_gnl(buff);
	str = (char *)malloc(((len + 1) * sizeof(char)));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	if (gnl)
		while (gnl[++i] != '\0')
			str[i] = gnl[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen_gnl(gnl) + ft_strlen_gnl(buff)] = '\0';
	return (str);
}

char	*ft_strjoin_gnl(char *gnl, char *buff)
{
	char	*str;

	if (!gnl)
	{
		gnl = (char *)malloc(1 * sizeof(char));
		if (!gnl)
			return (NULL);
		gnl[0] = '\0';
	}
	if (!gnl || !buff)
		return (NULL);
	str = join_dup(gnl, buff);
	free(gnl);
	return (str);
}
