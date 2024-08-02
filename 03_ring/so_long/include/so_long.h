/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:26:44 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/08/02 21:03:21 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>

# define PX 50

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*window;
	char	**map;
	int		high;
	int		lenght;
	int		collect;
	int		player;
	int		x;
	int		y;
}	t_mlx_data;

int		ft_count_file(char *file);
char	**ft_init_map(char *file);
void	free_map(char **map);
void	count_size(t_mlx_data *data);
void	content_review(t_mlx_data *data);
void	errmap_ex(t_mlx_data *data);
void	check_content(t_mlx_data *data);

#endif
