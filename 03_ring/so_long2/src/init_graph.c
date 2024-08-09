/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:05:12 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/08/08 21:45:23 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_assets(t_mlx_data *data)
{
	int	px;

	px = PX;
	data->assets = malloc(sizeof(t_assets));
	if (!data->assets)
		close_all(data);
	data->assets->background = mlx_xpm_file_to_image(data->mlx_ptr,
			BACKGROUND, &px, &px);
	data->assets->wall = mlx_xpm_file_to_image(data->mlx_ptr,
			WALL, &px, &px);
	data->assets->collect = mlx_xpm_file_to_image(data->mlx_ptr,
			COLLECT, &px, &px);
	data->assets->open = mlx_xpm_file_to_image(data->mlx_ptr,
			OPEN_EXIT, &px, &px);
	data->assets->close = mlx_xpm_file_to_image(data->mlx_ptr,
			CLOSE_EXIT, &px, &px);
	data->assets->player1 = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYER1, &px, &px);
}

void	draw_map_to_screen(t_mlx_data *data, int y, int x)
{
	if (data->map[y][x] == '0')
		mlx_put_image_to_window(data->mlx_ptr,
			data->window, data->assets->background, x * PX, y * PX);
	else if (data->map[y][x] == '1')
		mlx_put_image_to_window(data->mlx_ptr,
			data->window, data->assets->wall, x * PX, y * PX);
	else if (data->map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx_ptr,
			data->window, data->assets->collect, x * PX, y * PX);
	else if (data->map[y][x] == 'E' && data->collect > 0)
		mlx_put_image_to_window(data->mlx_ptr,
			data->window, data->assets->close, x * PX, y * PX);
	else if (data->map[y][x] == 'E' && data->collect <= 0)
		mlx_put_image_to_window(data->mlx_ptr,
			data->window, data->assets->open, x * PX, y * PX);
	else if (data->map[y][x] == 'P')
		mlx_put_image_to_window(data->mlx_ptr,
			data->window, data->assets->player1, x * PX, y * PX);
}

int	init_screen(t_mlx_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			draw_map_to_screen(data, y, x);
			x++;
		}
		y++;
	}
	return (0);
}
