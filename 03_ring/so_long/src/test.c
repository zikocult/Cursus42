/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 16:57:49 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/07/31 09:48:12 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define WIDTH 400
#define HEIGHT 400

#include "../minilibx-linux/mlx.h"
// #include "../libft/include/ft_printf.h"
#include <ft_printf.h>
#include <stdlib.h>

int main(void)
{
	void 	*mlx_ptr;
	void	*mlx_window;
	
	ft_printf("testeand\n");
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (1);

	// Con esta función creamos la nueva ventana, le he dado los tamaños definidos
	// arriba para poder modificarlos a placer
	mlx_window = mlx_new_window(mlx_ptr, HEIGHT, WIDTH, "Patata");
	// Nótese que en caso de fallo, debemos liberar todo lo anterior.
	if(!mlx_window)
	{
		mlx_destroy_display(mlx_ptr);
		free(mlx_ptr);
		return (1);
	}
	// Todo esto quedará almacenado en una nueva estructura, que vendría a ser:
	// typedef struct	s_win_list
	// {
	// 	Window				window;
	// 	GC					gc;
	// 	struct s_win_list	*next;
	// 	int					(*mouse_hook)();
	// 	int					(*key_hook)();
	// 	int					(*expose_hook)();
	// 	void				*mouse_param;
	// 	void				*key_param;
	// 	void				*expose_param;
	// 	t_event_list		hooks[MLX_MAX_EVENT];
	// }				t_win_list;

	// Para que no se cierre la ventana tan sólo abrirla, necesitamos de la 
	// siguiente función, que lo que hace es mantener la ventana abierta:
	mlx_loop(mlx_ptr);

	// Y esta función sería la que cerraría y liberaría la ventana:
	mlx_destroy_window(mlx_ptr, mlx_window);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);

	// Para cerrar todo correctamente y sin leaks, necesitamos tratar con 
	// eventos, que veremos en breve, ahora mismo la única manera que tengo
	// de cerrar la ventan es mediante Ctrl + C y eso provoca que no lleguemos
	// a las lineas de liberación de la memoria, seguiré en próximos ejercicios
	// en esta misma carpeta
	return (0);
}
