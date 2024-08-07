/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:05:12 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/08/07 18:41:18 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_assets(t_mlx_data *data)
{
	int px;

	px = PX;
	data->assets.background = mlx_xpm_file_to_image(data->mlx_ptr, BACKGROUND, &px, &px);
	data->assets.wall = mlx_xpm_file_to_image(data->mlx_ptr, WALL1, &px, &px); 
	data->assets.collect = mlx_xpm_file_to_image(data->mlx_ptr, COLLECT, &px, &px); 
	data->assets.open = mlx_xpm_file_to_image(data->mlx_ptr, OPEN_EXIT, &px, &px); 
	data->assets.close = mlx_xpm_file_to_image(data->mlx_ptr, CLOSE_EXIT, &px, &px); 
	data->assets.enemy = mlx_xpm_file_to_image(data->mlx_ptr, ENEMY, &px, &px); 
	data->assets.player1 = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER1, &px, &px); 
	data->assets.player2 = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER2, &px, &px); 
	data->assets.player3 = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER3, &px, &px); 
	data->assets.player4 = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER4, &px, &px); 
}

void	init_screen(t_mlx_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y])	
	{
		x = 0;
		while (data->map[y][x])
		{
			if(data->map[y][x] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->window, data->assets.background, x * PX, y * PX);
			else if(data->map[y][x] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->window, data->assets.wall, x * PX, y * PX);
			else if(data->map[y][x] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->window, data->assets.collect, x * PX, y * PX);
			else if(data->map[y][x] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->window, data->assets.close, x * PX, y * PX);
			else if(data->map[y][x] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->window, data->assets.player1, x * PX, y * PX);
			x++;	
		}
		y++;
	}
}
