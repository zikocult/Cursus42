/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 21:07:10 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/07/31 22:43:41 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
		errmap_ex(data);	
}

void	check_char(t_mlx_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P' || data->map[i][j] == 'E'
				|| data->map[i][j] == '1' || data->map[i][j] == 'C'
				|| data->map[i][j] == '0')
				j++;
			else
				errmap_ex(data);
		}
		i++;
	}
}


void	check_set(t_mlx_data *data)
{
	int	i;
	int	j;
	int	ex;

	i = 0;
	j = 0;
	ex = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == 'P')
				data->player += 1;
			else if (data->map[j][i] == 'E')
				ex++;
			else if (data->map[j][i] == 'C')
				data->collect += 1;
			i++;
		}
		j++;
	}
	if (data->collect == 0 || data->player == 0
		|| ex == 0 || data->player > 1)
		errmap_ex(data);
}

void	check_content(t_mlx_data *data)
{
	data->player = 0;
	data->collect = 0;
	check_wall(data);
	check_char(data);
	check_set(data);
}
