/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:17:23 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/08/12 12:04:31 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	aux_map_init(t_mlx_data *data, t_aux_map *aux_map)
{
	int	i;

	i = 0;
	aux_map->count_c = 0;
	aux_map->count_e = 0;
	aux_map->map = (char **)ft_calloc(data->high + 1, sizeof(char *));
	if (!aux_map->map)
		return ;
	while (i < data->high)
	{
		aux_map->map[i] = ft_strdup(data->map[i]);
		if (!aux_map->map[i])
		{
			while (i >= 0)
				free(aux_map->map[i--]);
			free(aux_map->map);
			aux_map->map = NULL;
			return ;
		}
		i++;
	}
}

static void	flood_fill(t_mlx_data *data, t_aux_map *aux_map, int y, int x)
{
	if (x < 0 || y < 0 || x >= data->lenght || y >= data->high
		|| aux_map->map[y][x] == '1')
		return ;
	else if (aux_map->map[y][x] == 'E')
	{
		aux_map->count_e += 1;
		aux_map->map[y][x] = '1';
		return ;
	}
	else if (aux_map->map[y][x] == 'C')
		aux_map->count_c += 1;
	aux_map->map[y][x] = '1';
	if (y + 1 < data->high && (aux_map->map[y + 1][x] != 1
		|| aux_map->map[y + 1][x] != 'X'))
		flood_fill(data, aux_map, y + 1, x);
	if (y - 1 >= 0 && (aux_map->map[y - 1][x] != 1
		|| aux_map->map[y - 1][x] != 'X'))
		flood_fill(data, aux_map, y - 1, x);
	if (x + 1 < data->lenght && (aux_map->map[y][x - 1] != 1
		|| aux_map->map[y][x - 1] != 'X'))
		flood_fill(data, aux_map, y, x - 1);
	if (x - 1 >= 0 && (aux_map->map[y][x + 1] != 1
		|| aux_map->map[y][x + 1] != 'X'))
		flood_fill(data, aux_map, y, x + 1);
}

int	check_path(t_mlx_data *data)
{
	t_aux_map	aux_map;

	aux_map_init(data, &aux_map);
	if (!aux_map.map)
		errmap_ex(data);
	flood_fill(data, &aux_map, data->player.y, data->player.x);
	free_map(aux_map.map);
	if (aux_map.count_c != data->collect || aux_map.count_e != 1)
		return (1);
	return (0);
}
