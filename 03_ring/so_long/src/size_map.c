/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:36:21 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/07/31 21:16:04 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	errmap_ex(t_mlx_data *data)
{
	free_map(data->map);
	ft_printf("Error\n");
	exit(1);
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
		if (ft_strlen(data->map[i]) != data->lenght)
			errmap_ex(data);
		i++;
	}
}
