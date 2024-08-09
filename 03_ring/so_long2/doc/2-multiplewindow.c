/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-multiplewindow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:57:49 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/07/29 18:05:38 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define WIDTH 400
#define HEIGHT 400

#include "minilibx-linux/mlx.h"
#include <stdlib.h>

int main(void)
{
	void 	*mlx_ptr;
	void	*mlx_window1;
	void	*mlx_window2;
	
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (1);
	mlx_window1 = mlx_new_window(mlx_ptr, HEIGHT, WIDTH, "Patata LOCA!");
	if(!mlx_window1)
	{
		mlx_destroy_display(mlx_ptr);
		free(mlx_ptr);
		return (1);
	}
	mlx_window2 = mlx_new_window(mlx_ptr, HEIGHT, WIDTH, "Sin patatas: YUCA!");
	if(!mlx_window2)
	{
		mlx_destroy_display(mlx_ptr);
		free(mlx_ptr);
		return (1);
	}
	mlx_loop(mlx_ptr);

	mlx_destroy_window(mlx_ptr, mlx_window1);
	mlx_destroy_window(mlx_ptr, mlx_window2);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	return (0);
}
