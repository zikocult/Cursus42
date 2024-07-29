/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0-init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:57:49 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/07/29 19:09:09 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define WIDTH 800
#define HEIGHT 800

#include "minilibx-linux/mlx.h"
#include <stdlib.h>

int main(void)
{
	// El proyecto minilibx-linux, se encuentra en la dirección:
	// https://github.com/42Paris/minilibx-linux
	
	void *mlx_ptr;
	
	// En esta variable, guardaremos lo que inicialicemos y se creará una 
	// estructura tal que:
	//
	// typedef struct s_xvar
	// {
	// 	Display		*display;
	// 	Window		root;
	// 	int			screen;
	// 	int			depth;
	// 	Visual		*visual;
	// 	Colormap	cmap;
	// 	int			prinvate_cmap;
	// 	t_win_list	*win_list;
	// 	int			(*loop_hook)();
	// 	void		*loop_param;
	// 	int			use_xshm;
	// 	int			pshm_format;
	// 	int			do_flush;
	// 	int			decrbg[6];
	// 	Atom		wm_delete_window;
	// 	Atom		wm_protocols;
	// 	int			end_loop;
	// } t_xvar;
	//
	// En el campo Display, es donde se creará la conexión con el servidor X.
	// El resto de la estructura contiene todos los datos necesarios para que 
	// minilibx-linux, haga sus cosas.

	// Inicialicemos la variable
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (1);

	// Con esto cerramos el display
	mlx_destroy_display(mlx_ptr);
	// La inicialización comprende un malloc a la estructura xvar que 
	// debemos liberar.
	free(mlx_ptr);
	// Es necesario destroy y free, pues destroy libera la memoria de los 
	// elementos almacenados por las funciones y free libera el puntero en si.
	// Si no estuvieran ambos, tendríamos leaks.


	// hago un resumen de todos los flags para compilar (no es necesario mover
	// los *.a):
	// * -Lminilibx-linux : es la dirección local dónde está alojada la librería
	// * -lmlx_Linux : esta opción realiza el link contra los *.a o *.so 
	// * -lX11 : hace el link contra la librería X11, la cual es el interfaz
	// gráfico de usuario
	// * -lXext : link contra Xext, provee las extensiones para X Window System
	//
	// Quedaría algo como:
	// gcc test.c -Lminilibx-linux -lmlx_Linux -lX11 -lXext
	
	return (0);
}
