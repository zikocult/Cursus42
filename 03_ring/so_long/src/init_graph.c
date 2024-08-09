/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:05:12 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/08/09 12:47:25 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	player_asset(t_mlx_data *data, int *px)
{
	data->assets->player1 = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYER1, px, px);
	data->assets->player2 = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYER2, px, px);
	data->assets->player3 = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYER3, px, px);
	data->assets->player4 = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYER4, px, px);
}

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
	data->assets->enemy = mlx_xpm_file_to_image(data->mlx_ptr,
			ENEMY, &px, &px);
	player_asset(data, &px);
}

void	pj_movement(t_mlx_data *data, int y, int x)
{
	if (data->player.picture == 0)
		mlx_put_image_to_window(data->mlx_ptr,
			data->window, data->assets->player1, x * PX, y * PX);
	if (data->player.picture == 1)
		mlx_put_image_to_window(data->mlx_ptr,
			data->window, data->assets->player2, x * PX, y * PX);
	if (data->player.picture == 2)
		mlx_put_image_to_window(data->mlx_ptr,
			data->window, data->assets->player3, x * PX, y * PX);
	if (data->player.picture == 3)
		mlx_put_image_to_window(data->mlx_ptr,
			data->window, data->assets->player4, x * PX, y * PX);
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
	else if (data->map[y][x] == 'X')
		mlx_put_image_to_window(data->mlx_ptr,
			data->window, data->assets->enemy, x * PX, y * PX);
	else if (data->map[y][x] == 'P')
		pj_movement(data, y, x);
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
