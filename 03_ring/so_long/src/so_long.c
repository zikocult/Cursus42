/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:35:25 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/08/07 18:45:14 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	handle_input(int keysym, t_mlx_data *data)
{
	if(keysym == XK_Escape)
	{
		ft_printf("BYE!\n", keysym);
		close_all(data);
	}
	else if (keysym == XK_w || keysym == XK_W)
	{
		mlx_string_put(data->mlx_ptr, data->window, 150, 20, 0xff0000, "Move UP!");
		ft_printf("Move UP!\n");

	}
	else if (keysym == XK_a || keysym == XK_A)
	{
		mlx_string_put(data->mlx_ptr, data->window, 20, 100, 0x0000ff, "Move LEFT!");
		ft_printf("Move LEFT!\n");

	}
	else if (keysym == XK_s || keysym == XK_S)
	{
		mlx_string_put(data->mlx_ptr, data->window, 150, 150, 0x00ff00, "Move DOWN!");
		ft_printf("Move DOWN!\n");
	}
	else if (keysym == XK_d || keysym == XK_D)
	{
		mlx_string_put(data->mlx_ptr, data->window, 250, 100, 0xffffff, "Move RIGHT!");
		ft_printf("Move RIGHT!\n");
	}
	else
		ft_printf("The %d key has been pressed\n", keysym);
	return (0);
}

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
			ft_printf("Error name or extension\n");
			exit (1);
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
		test_name(argv[1], ".ber");
		data.map = ft_init_map(argv[1]);
		if (!data.map)
			return (1);
		count_size(&data);
		check_content(&data);
		data.mlx_ptr = mlx_init();
		if (!data.mlx_ptr)
			errmap_ex(&data);	
		data.window = mlx_new_window(data.mlx_ptr, data.lenght * PX, data.high * PX, "SO_LONG");
		if (!data.window)
			close_all(&data);
		init_assets(&data);
		init_screen(&data);
		mlx_key_hook(data.window, handle_input, &data);
		mlx_loop(data.mlx_ptr);
	}
	else
		ft_printf("Error number arguments\n");
	return (0);
}
