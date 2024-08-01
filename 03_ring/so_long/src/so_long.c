/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:35:25 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/08/01 15:59:29 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


void	close_all(t_mlx_data *data)
{
	free_map(data->map);
	mlx_destroy_window(data->mlx_ptr, data->window);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit (1);
}

int	handle_input(int keysym, t_mlx_data *data)
{
	if(keysym == XK_Escape)
	{
		ft_printf("BYE!\n", keysym);
		close_all(data);
	}
	else if (keysym == XK_w || keysym == XK_W)
	{
		mlx_clear_window(data->mlx_ptr, data->window);
		mlx_string_put(data->mlx_ptr, data->window, 20, 20, 0xff0000, "Move UP!");
		ft_printf("Move UP!\n");

	}
	else if (keysym == XK_a || keysym == XK_A)
		ft_printf("Move LEFT!\n");
	else if (keysym == XK_s || keysym == XK_S)
		ft_printf("Move DOWN!\n");
	else if (keysym == XK_d || keysym == XK_D)
		ft_printf("Move RIGHT!\n");
	else
		ft_printf("The %d key has been pressed\n", keysym);
	(void) *data;
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
		data.map = ft_init_map(argv[1]);
		if (!data.map)
			return (1);
		count_size(&data);
		check_content(&data);
		data.mlx_ptr = mlx_init();
		if (!data.mlx_ptr)
			errmap_ex(&data);	
		data.window = mlx_new_window(data.mlx_ptr, data.lenght * 32, data.high * 32, "Patatona!");
		if (!data.window)
			close_all(&data);
		mlx_key_hook(data.window, handle_input, &data);
		mlx_loop(data.mlx_ptr);
	}
	else
		ft_printf("Error\n");
	return (0);
}
