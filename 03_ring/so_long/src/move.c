/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:46:26 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/08/09 12:13:28 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_it(t_mlx_data *data, int y, int x)
{
	if (data->player.picture == 0)
		data->player.picture = 1;
	else if (data->player.picture == 1)
		data->player.picture = 2;
	else if (data->player.picture == 2)
		data->player.picture = 3;
	else if (data->player.picture == 3)
		data->player.picture = 0;
	data->map[data->player.y][data->player.x] = '0';
	data->map[data->player.y + y][data->player.x + x] = 'P';
	data->player.y += y;
	data->player.x += x;
	data->moves += 1;
}

void	player_move(t_mlx_data *data, int y, int x)
{
	if (data->map[data->player.y + y][data->player.x + x] == '0')
		move_it(data, y, x);
	else if (data->map[data->player.y + y][data->player.x + x] == 'C')
	{
		move_it(data, y, x);
		data->collect -= 1;
	}
	else if (data->map[data->player.y + y][data->player.x + x] == 'E'
		&& data->collect == 0)
	{
		ft_printf("YOU WIN!\n");
		close_all(data);
	}
	else if (data->map[data->player.y + y][data->player.x + x] == 'X')
	{
		ft_printf("YOU LOSE!\n");
		close_all(data);
	}
}
