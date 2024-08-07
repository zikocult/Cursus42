/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:26:44 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/08/07 14:18:07 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>

# define PX 50
# define WALL "./assets/muro.xpm"
# define WALL1 "./assets/muro1.xpm"
# define COLLECT "./assets/colection.xpm"
# define COLLECT2 "./assets/colection2.xpm"
# define OPEN_EXIT "./assets/open.xpm"
# define CLOSE_EXIT "./assets/closed.xpm"
# define ENEMY "./assets/enemy.xpm"
# define BACKGROUND "./assets/back.xpm"
# define PLAYER1 "./assets/Persona1.xpm"
# define PLAYER2 "./assets/Persona2.xpm"
# define PLAYER3 "./assets/Persona3.xpm"
# define PLAYER4 "./assets/Persona4.xpm"

typedef struct s_assets
{
	void	*wall;
	void	*collect;
	void	*open;
	void	*close;
	void	*enemy;
	void	*background;
	void	*player1;
	void	*player2;
	void	*player3;
	void	*player4;
}	t_assets;

typedef struct s_player
{
	int	quantity;
	int	x;
	int y;
	int picture;
}	t_player;

typedef struct s_mlx_data
{
	void		*mlx_ptr;
	void		*window;
	char		**map;
	int			high;
	int			lenght;
	int			collect;
	int			moves;
	int			out;
	t_player	player;
	t_assets	assets;
}	t_mlx_data;

int		ft_count_file(char *file);
char	**ft_init_map(char *file);
void	count_size(t_mlx_data *data);
void	free_map(char **map);
void	close_all(t_mlx_data *data);
void	errmap_ex(t_mlx_data *data);
void	content_review(t_mlx_data *data);
void	check_content(t_mlx_data *data);
void	init_assets(t_mlx_data *data);
void	init_screen(t_mlx_data *data);

#endif
