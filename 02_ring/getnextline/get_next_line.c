/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:34:43 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/07/07 00:53:00 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	last_line(char *str_gnl, char *str_tmp, char *temp)
{
	int			i;
	int			len;
	
	i = 0;
	if (!temp)
	{
		temp = (char *)malloc(1 * sizeof(char));
		temp[0] = '\0';
		return (0);
	}
	len = ft_strlen(temp);
	if (temp[i] != '\0')
	{
		str_gnl = ft_strjoin2(str_gnl, str_tmp);
		free(temp);
	}
	return (len);
}

char	*new_line(char *str_gnl, char *str_tmp)
{
	static char	*temp;
	char		*str_gnl_tmp;
	int			total_len;

	if (!str_tmp)
		return (NULL);
	total_len = ft_strlen(str_gnl) + ft_strlen(str_tmp) + last_line(str_gnl, str_tmp, temp);
	str_gnl_tmp = ft_strdup(str_gnl);
	free(str_gnl);
	str_gnl = (char *)malloc((total_len + 1) * sizeof(char));
	if (!str_gnl)
		return (NULL);
	str_gnl = ft_strjoin(str_gnl_tmp, str_tmp, temp);
	free(str_gnl_tmp);
	free(str_tmp);
	return (str_gnl);
}

char	*get_next_line(int fd)
{
	static char	*str_gnl;
	char		*str_tmp;
	ssize_t		read_gnl;

	if (BUFFER_SIZE < 1)
		return (NULL);
	if (!str_gnl)
	{
		str_gnl = (char *)malloc(1 * sizeof(char));
		*str_gnl = '\0';
	}
	str_tmp = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!str_tmp)
		return (NULL);
	read_gnl = read(fd, str_tmp, BUFFER_SIZE);
	if (read_gnl == -1)
	{
		free(str_tmp);
		free(str_gnl);
		return (NULL);
	}
	str_tmp[read_gnl] = '\0';
	str_gnl = new_line(str_gnl, str_tmp);
	return (str_gnl);
}

int main (void)
{
	char *str_gnl;
	ssize_t	fd;
	int	i;

	i = 0;
	printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Caraculo!");
		return (1);
	}
	while (i++ < 7)
	{
		printf("%s\n---------\n", str_gnl = get_next_line(fd));
	}
	close(fd);
	free(str_gnl);

	return (0);
}
