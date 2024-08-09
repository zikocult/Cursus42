/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:46:15 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/08/09 11:31:22 by gbaruls-         ###   ########.fr       */
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

void	count_size(t_mlx_data *data)
{
	int	i;

	i = 0;
	data->lenght = ft_strlen(data->map[i]);
	while (data->map[i])
		i++;
	data->high = i;
	if (data->high == 0 || data->lenght == 0)
		errmap_ex(data);
	if (data->high == data->lenght)
		errmap_ex(data);
	i = 0;
	while (data->map[i])
	{
		if (ft_strlen(data->map[i]) != (size_t)data->lenght)
			errmap_ex(data);
		i++;
	}
}
