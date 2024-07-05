/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:34:43 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/07/05 14:07:57 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*new_line(char *str_gnl, char *str_tmp)
{
	char	*str_gnl_tmp;
	int		total_len;
	int		i;
	int		j;

	i = 0;
	if (!str_tmp)
		return (NULL);
	total_len = ft_strlen(str_gnl) + ft_strlen(str_tmp);
	str_gnl_tmp = ft_strdup(str_gnl);
	free(str_gnl);
	str_gnl = (char *)malloc((total_len + 1) * sizeof(char));
	if (!str_gnl)
		return (NULL);
	str_gnl = ft_strjoin(str_gnl_tmp, str_tmp);
	return (str_gnl);
}

char	*get_next_line(int fd)
{
	static char	*str_gnl;
	char		*str_tmp;
	ssize_t		read_gnl;

	if (BUFFER_SIZE < 1)
		return (NULL);
	str_tmp = (char *)malloc(10 + 1 * sizeof(char));
	printf("%p\n", str_tmp);
	if (!str_tmp)
		return (NULL);
	read_gnl = read(fd, str_tmp, 10);
	if (read_gnl == -1)
	{
		//haig de posar tots els free dels malloc
		return (NULL);
	}
	str_tmp[read_gnl] = '\0';
	return (str_tmp);
	// return (new_line(str_gnl, str_tmp));
}

int main (void)
{
	ssize_t	fd;
	ssize_t		read_gnl;
	char		*str_tmp;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Caraculo!");
		return (1);
	}
	printf("%s\n", get_next_line(fd));
	close(fd);

	return (0);
}
