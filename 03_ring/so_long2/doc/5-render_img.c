/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5-render_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:57:49 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/07/30 11:43:19 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define WIDTH 800
#define HEIGHT 800

typedef unsigned char byte; ;

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*window;
	t_img	img;
}			t_mlx_data;

#include "minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	// Line len is in bytes WIDTH 800 len_line ~3200 (can differ for aligment)
	offset = (img->line_len * y) + (x *(img->bits_per_pixel / 8));
	*((unsigned int *)(offset + img->img_pixels_ptr)) = color;
}

void	color_screen(t_mlx_data *data, int color)
{
	for (int y = 0; y < HEIGHT; y++)
		for (int x = 0; x < WIDTH; x++)
			my_pixel_put(&data->img, x, y, color);
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
		color_screen(data, 0xff0000);
	else if(keysym == XK_g)
		color_screen(data, 0x00ff00);
	else if(keysym == XK_b)
		color_screen(data, 0x0000ff);
	else if(keysym == XK_w)
		color_screen(data, 0xffffff);
	else if(keysym == XK_space)
		color_screen(data, 0x000000);
	else
		printf("The %d key has been pressed\n", keysym);
	mlx_put_image_to_window(data->mlx_ptr, data->window, data->img.img_ptr, 0, 0);
	return (0);
}

int main(void)
{
	t_mlx_data	data;
	
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.window = mlx_new_window(data.mlx_ptr, HEIGHT, WIDTH, "Patata rapida");
	if(!data.window)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return (1);
	}
	data.img.img_ptr = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
	data.img.img_pixels_ptr = mlx_get_data_addr(data.img.img_ptr, &data.img.bits_per_pixel, &data.img.line_len, &data.img.endian);
	printf("Line_len %d <-> WIDTH %d \nbpp %d\nendian %d\n", data.img.line_len, WIDTH, data.img.bits_per_pixel, data.img.endian);
	mlx_key_hook(data.window, handle_input, &data); 

	mlx_loop(data.mlx_ptr);
	mlx_destroy_window(data.mlx_ptr, data.window);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}
