/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:35:25 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/07/31 22:28:44 by Guillem Barulls  ###   ########.fr       */
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
			ft_printf("Error\n");
			return (1);
		}
		len++;
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx_data	data;

	if (argc == 2)
	{
		if (test_name(argv[1], ".ber") == 1)
			return (1);
		if (ft_count_file(argv[1]) == -1)
			return (1);
		data.map = ft_init_map(argv[1]);
		if (!data.map)
			return (1);
		count_size(&data);
		check_content(&data);
		data.mlx_ptr = mlx_init();
		// Todo lo siguiente es temporal, se deberá poner en la función de salida
		// con el hook de escape
		mlx_destroy_display(data.mlx_ptr);
		free_map(data.map);
		free(data.mlx_ptr);
	}
	else
		ft_printf("Error\n");
	return (0);
}
