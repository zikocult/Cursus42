/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 21:07:10 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/08/15 11:51:03 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	test_name(char *str, char *map_ext)
{
	int		len;
	int		i;

	len = ft_strlen(str) - 4;
	i = 0;
	while (str[len])
	{
		if (str[len] != map_ext[i])
		{
			ft_printf("Error extension del mapa\n");
			exit (1);
		}
		len++;
		i++;
	}
	return (0);
}

void	check_wall(t_mlx_data *data)
{
	int	i;
	int	err;

	err = 0;
	i = 0;
	while (i < data->high && err == 0)
	{
		if (data->map[i][0] != '1' || data->map[i][data->lenght - 1] != '1')
			err = 1;
		i++;
	}
	i = 0;
	while (i < data->lenght && err == 0)
	{
		if (data->map[0][i] != '1' || data->map[data->high - 1][i] != '1')
			err++;
		i++;
	}
	if (err > 0)
	{
		ft_printf("Los muros no rodean el mapa!\n");
		errmap_ex(data);
	}
}

void	check_char(t_mlx_data *data, int y, int x)
{
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P' || data->map[y][x] == 'E'
				|| data->map[y][x] == '1' || data->map[y][x] == 'C'
				|| data->map[y][x] == '0' || data->map[y][x] == 'X')
				x++;
			else
			{
				ft_printf("Carácteres inválidos dentro del mapa!\n");
				errmap_ex(data);
			}
		}
		y++;
	}
}

void	check_set(t_mlx_data *data, int y, int x)
{
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				data->player.quantity += 1;
				data->player.x = x;
				data->player.y = y;
			}
			if (data->map[y][x] == 'E')
				data->out += 1;
			else if (data->map[y][x] == 'C')
				data->collect += 1;
			x++;
		}
		y++;
	}
	if (data->collect == 0 || data->player.quantity != 1
		|| data->out != 1)
	{
		ft_printf("Fallo en el set de objetos necesarios\n");
		errmap_ex(data);
	}
}

void	check_content(t_mlx_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	data->player.quantity = 0;
	data->player.picture = 0;
	data->collect = 0;
	data->out = 0;
	data->moves = 0;
	count_size(data);
	check_wall(data);
	check_char(data, y, x);
	check_set(data, y, x);
	if (check_path(data))
	{
		ft_printf("Error para encontrar un camino real\n");
		errmap_ex(data);
	}
}
