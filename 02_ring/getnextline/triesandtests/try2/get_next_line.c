/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:00:24 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/07/08 20:03:54 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_all(int fd, char *gnl)
{
	char	*buff;
	int		read_bytes;

	buff = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(gnl, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		gnl = ft_strjoin(gnl, buff);
	}
	free(buff);
	return (gnl);
}

char	*get_line(char *gnl)
{
	int		i;
	char	*str;

	i = 0;
	if (!gnl)
		return (NULL);
	while (gnl[i] != '\n' && gnl[i] != '\0')
		i++;
	str = (char *)malloc(i + 1 * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (gnl[i] != '\n' && gnl[i] != '\0')
	{
		str[i] = gnl[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next(char *gnl)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (gnl[i] != '\n' && gnl[i] != '\0')
		i++;
	if (gnl[i] == '\0')
	{
		free(gnl);
		return (NULL);
	}
	i++;
	str = (char *)malloc(ft_strlen(gnl) - i + 1 * sizeof(char));
	if (!str)
		return (NULL);
	while (gnl[i] != '\0')
		str[j++] = gnl[i++];
	str[j] = '\0';
	free(gnl);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*gnl_str;
	char		*line;

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	gnl_str = read_all(fd, gnl_str);
	if (!gnl_str)
		return (NULL);
	line = get_line(gnl_str);
	gnl_str = get_next(gnl_str);
	return (line);
}
