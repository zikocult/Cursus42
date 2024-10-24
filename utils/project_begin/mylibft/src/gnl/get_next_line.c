/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 20:13:14 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/07/30 13:11:19 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
#include <unistd.h>

char	*ft_read_all(int fd, char *gnl_str)
{
	char	*buff;
	int		rd_bytes;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr_gnl(gnl_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		gnl_str = ft_strjoin_gnl(gnl_str, buff);
	}
	free(buff);
	return (gnl_str);
}

char	*ft_get_line(char *gnl_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!gnl_str[i])
		return (NULL);
	while (gnl_str[i] && gnl_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (gnl_str[i] && gnl_str[i] != '\n')
	{
		str[i] = gnl_str[i];
		i++;
	}
	if (gnl_str[i] == '\n')
	{
		str[i] = gnl_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_save_line(char *gnl_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (gnl_str[i] && gnl_str[i] != '\n')
		i++;
	if (!gnl_str[i])
	{
		free(gnl_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen_gnl(gnl_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (gnl_str[i])
		str[j++] = gnl_str[i++];
	str[j] = '\0';
	free(gnl_str);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*gnl_str[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (gnl_str[fd])
			free(gnl_str[fd]);
		return (NULL);
	}
	gnl_str[fd] = ft_read_all(fd, gnl_str[fd]);
	if (!gnl_str[fd])
		return (NULL);
	line = ft_get_line(gnl_str[fd]);
	gnl_str[fd] = ft_save_line(gnl_str[fd]);
	return (line);
}
