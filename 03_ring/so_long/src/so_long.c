/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:35:25 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/08/09 13:33:38 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	escape_function(t_mlx_data *data)
{
	ft_printf("Hard Game for you?\n");
	close_all(data);
}

void	moves_input(t_mlx_data *data)
{
	char	*move;

	move = ft_itoa(data->moves);
	mlx_clear_window(data->mlx_ptr, data->window);
	mlx_string_put(data->mlx_ptr, data->window,
		20, data->high * PX + 20, 0xff0000, "Movimiento: ");
	mlx_string_put(data->mlx_ptr, data->window,
		100, data->high * PX + 20, 0x00ff00, move);
	free (move);
}

int	handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
		escape_function(data);
	else if (keysym == XK_w || keysym == XK_W || keysym == XK_Up)
	{
		player_move(data, -1, 0);
		ft_printf("Llevas %i movimientos\n", data->moves);
	}
	else if (keysym == XK_a || keysym == XK_A || keysym == XK_Left)
	{
		player_move(data, 0, -1);
		ft_printf("Llevas %i movimientos\n", data->moves);
	}
	else if (keysym == XK_s || keysym == XK_S || keysym == XK_Down)
	{
		player_move(data, 1, 0);
		ft_printf("Llevas %i movimientos\n", data->moves);
	}
	else if (keysym == XK_d || keysym == XK_D || keysym == XK_Right)
	{
		player_move(data, 0, 1);
		ft_printf("Llevas %i movimientos\n", data->moves);
	}
	moves_input(data);
	return (0);
}

void	init_game(t_mlx_data *data)
{
	check_content(data);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		errmap_ex(data);
	data->window = mlx_new_window(data->mlx_ptr,
			data->lenght * PX, data->high * PX + 30, "SO_LONG");
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
