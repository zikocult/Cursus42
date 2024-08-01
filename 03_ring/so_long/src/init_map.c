/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:46:15 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/08/01 14:31:34 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <unistd.h>
#include <fcntl.h>

int	ft_count_file(char *file)
{
	int		counter;
	char	caracter;
	int		fd;

	counter = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\n");
		 exit (1);
	}
	while (read(fd, &caracter, 1) == 1)
		counter++;
	close(fd);
	return (counter);
}

char	*ft_load_file(char *file, int count)
{
	int		fd;
	ssize_t	nr_bytes;
	char	*buff;

	buff = (char *)malloc(sizeof(char) * count + 1);
	if (!buff)
		return (0);
	fd = open(file, O_RDONLY);
	nr_bytes = read(fd, buff, count);
	if (fd == -1)
		return (0);
	if (nr_bytes == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	close(fd);
	return (buff);
}

char	**ft_init_map(char *file)
{
	char	*buff;
	char	**map;
	int		count;

	count = ft_count_file(file);
	buff = ft_load_file(file, count);
	if (!buff)
		return (0);
	map = ft_split(buff, '\n');
	free (buff);
	return (map);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	while (i--)
		free(map[i]);
	free(map);
}
