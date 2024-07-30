/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-events.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:57:49 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/07/29 20:54:28 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define WIDTH 800
#define HEIGHT 800

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*window;
	int		color;
} t_mlx_data;

#include "minilibx-linux/mlx.h"
#include <X11/keysym.h>
// #include <X11/X.h> he posat events de minilib millor
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

// HANDLE FUNCTION:
// Cada vez que una tecla es presionada se llama a esta función
//
// KEYSYM vs KEYCODE
// El Keycode es un código específico del hardware, mientras que keysym 
// es una representación usada por el software para identificar la tecla
// ⛔ La versión MAC de minilib sólo usa keycodes ⛔
// Podemos chequear los defines:
// find / -name keysym.h 2>/dev/null
// find / -name keysymdef.h 2>/dev/null
// Para funcionar debemos tener la librería #include <X11/keysym.h>

int	handle_input(int keysym, t_mlx_data *data)
{
	// Por keycode el if quedaría como:
	// if(keysym == 65307)
	if(keysym == XK_Escape)
	{
		printf("The %d key (ESC) has been pressed\n", keysym);
		mlx_destroy_window(data->mlx_ptr, data->window);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
	printf("The %d key has been pressed\n", keysym);
	sleep(1); // Esto es para apreciar el hook
	return (0);
}

int	button_press(int button, int x, int y, t_mlx_data *data)
{
	if(button == 1)
		printf("Has apretado el botón izquierdo en (%d , %d)\n", x, y);
	else if(button == 3)
		printf("Has apretado el botón derecho en (%d , %d)\n", x, y);
	sleep(1); // Esto es para apreciar el hook
	return (0);
}

int     change_color(t_mlx_data *data)
{
    // Fill the window with the current color
	mlx_clear_window(data->mlx_ptr, data->window);
    mlx_string_put(data->mlx_ptr, data->window, 370, 370, data->color, "Cambiando de color");

	// Ciclo mediante los colores básicos
    if (data->color == 0xFF0000)        // Si es rojo
        data->color = 0x00FF00;        // Cambia a verde
    else if (data->color == 0x00FF00)   // Si es verde
        data->color = 0x0000FF;        // Cambia a azul
    else
        data->color = 0xFF0000;        // En otro caso, vuelve al rojo
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
	data.color = 0xFF0000; // Para comenzar con el rojo
	// HOOKS
	// "Hooking into events" (reaccionar a eventos)
	// Cuando aprieto una tecla, la función handle_input() será llamada
	// Cada evento eestá linkado a su propio prototipo
	// Para ello usaremos la siguiente función:
	mlx_key_hook(data.window, handle_input, &data); 

	// esto es para el ratón y tenemos que añadir la librería #include <X11/X.h>
	// para tener los eventos ButtonPress y ButtonPressMask
	// Esta sería la declaración si usamos la librería, pero estoy usando las
	// propias definiciones de minilibx-linux mas abajo.
	// mlx_hook(data.window, ButtonPress, ButtonPressMask, &button_press, &data);
	mlx_hook(data.window, 04, 1L<<2, &button_press, &data);

	// Esto es para dejar un loop en pantalla de alguna función
	mlx_loop_hook(data.mlx_ptr, change_color, &data);

	mlx_loop(data.mlx_ptr);

	mlx_destroy_window(data.mlx_ptr, data.window);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}
