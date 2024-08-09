/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:10:35 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/08/09 12:23:25 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdlib.h>

void	errmap_ex(t_mlx_data *data)
{
	free_map(data->map);
	ft_printf("Error map\n");
	exit(1);
}

void	free_assets(t_mlx_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->assets->background);
	mlx_destroy_image(data->mlx_ptr, data->assets->wall);
	mlx_destroy_image(data->mlx_ptr, data->assets->collect);
	mlx_destroy_image(data->mlx_ptr, data->assets->open);
	mlx_destroy_image(data->mlx_ptr, data->assets->close);
	mlx_destroy_image(data->mlx_ptr, data->assets->enemy);
	mlx_destroy_image(data->mlx_ptr, data->assets->player1);
	mlx_destroy_image(data->mlx_ptr, data->assets->player2);
	mlx_destroy_image(data->mlx_ptr, data->assets->player3);
	mlx_destroy_image(data->mlx_ptr, data->assets->player4);
	free(data->assets);
}

int	close_all(t_mlx_data *data)
{
	free_assets(data);
	free_map(data->map);
	mlx_destroy_window(data->mlx_ptr, data->window);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit (1);
	return (0);
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
