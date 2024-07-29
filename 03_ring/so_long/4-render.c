/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4-render.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:57:49 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/07/29 20:48:54 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define WIDTH 800
#define HEIGHT 800

typedef unsigned char byte; ;
typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*window;
} t_mlx_data;

#include "minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


int	encode_rgb(byte red, byte green, byte blue)
{
    return (red << 16 | green << 8 | blue);
}

void	color_screen(t_mlx_data *data, int color)
{
	// Esta función está copiada de Oceano, él mismo dice que es mala, pero 
	// como inicio está bien, después desarrollaremos una mejor opción, esta 
	// pinta pixel a pixel
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			mlx_pixel_put(data->mlx_ptr, data->window, x, y, color);
		}
	}
}

int	handle_input(int keysym, t_mlx_data *data)
{
	if(keysym == XK_Escape)
	{
		printf("The %d key (ESC) has been pressed\n", keysym);
		mlx_destroy_window(data->mlx_ptr, data->window);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
	else if(keysym == XK_r)
		color_screen(data, encode_rgb(0xff, 0, 0));
	else if(keysym == XK_g)
		color_screen(data, encode_rgb(0, 0xff, 0));
	else if(keysym == XK_b)
		color_screen(data, encode_rgb(0, 0, 0xff));
	else if(keysym == XK_w)
		color_screen(data, encode_rgb(0xff, 0xff, 0xff));
	else if(keysym == XK_space)
			color_screen(data, encode_rgb(0, 0, 0));
	else
		printf("The %d key has been pressed\n", keysym);
	return (0);
}

int main(void)
{
	t_mlx_data	data;
	
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.window = mlx_new_window(data.mlx_ptr, HEIGHT, WIDTH, "Patata");
	if(!data.window)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return (1);
	}
	mlx_key_hook(data.window, handle_input, &data); 

	mlx_loop(data.mlx_ptr);
	mlx_destroy_window(data.mlx_ptr, data.window);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}
