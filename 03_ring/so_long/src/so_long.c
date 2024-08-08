/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:35:25 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/08/08 19:47:37 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Remember la següent funció per a posar coses a pantalla
// mlx_string_put(data->mlx_ptr, data->window, 150, 20, 0xff0000, "Move UP!");

void	escape_function(t_mlx_data *data)
{
	ft_printf("Hard Game for you?\n");
	close_all(data);
}

int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
		escape_function(data);
	else if (keysym == XK_w || keysym == XK_W)
	{
		player_move(data, -1, 0);
		ft_printf("Llevas %i movimientos\n", data->moves);
	}
	else if (keysym == XK_a || keysym == XK_A)
	{
		player_move(data, 0, -1);
		ft_printf("Llevas %i movimientos\n", data->moves);
	}
	else if (keysym == XK_s || keysym == XK_S)
	{
		player_move(data, 1, 0);
		ft_printf("Llevas %i movimientos\n", data->moves);
	}
	else if (keysym == XK_d || keysym == XK_D)
	{
		player_move(data, 0, 1);
		ft_printf("Llevas %i movimientos\n", data->moves);
	}
	return (0);
}

void	init_game(t_mlx_data *data)
{
	check_content(data);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		errmap_ex(data);
	data->window = mlx_new_window(data->mlx_ptr,
			data->lenght * PX, data->high * PX, "SO_LONG");
	if (!data->window)
		close_all(data);
	init_assets(data);
}

int	main(int argc, char **argv)
{
	t_mlx_data	data;

	if (argc == 2)
	{
		test_name(argv[1], ".ber");
		data.map = ft_init_map(argv[1]);
		if (!data.map)
			return (1);
		init_game(&data);
		mlx_hook(data.window, 2, (1L << 0), &handle_input, &data);
		mlx_hook(data.window, 17, 0, &close_all, &data);
		mlx_loop_hook(data.mlx_ptr, &init_screen, &data);
		mlx_loop(data.mlx_ptr);
	}
	else
		ft_printf("Error number arguments\n");
	return (0);
}
