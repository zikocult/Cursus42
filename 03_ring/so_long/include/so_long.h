/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:26:44 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/08/12 12:05:31 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>

# define PX 50
# define WALL "./assets/muro1.xpm"
# define COLLECT "./assets/colection.xpm"
# define OPEN_EXIT "./assets/open.xpm"
# define CLOSE_EXIT "./assets/closed.xpm"
# define BACKGROUND "./assets/back.xpm"
# define ENEMY  "./assets/enemy.xpm"
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
	void	*background;
	void	*enemy;
	void	*player1;
	void	*player2;
	void	*player3;
	void	*player4;
}	t_assets;

typedef struct s_player
{
	int	quantity;
	int	x;
	int	y;
	int	picture;
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
	t_assets	*assets;
}	t_mlx_data;

typedef struct s_aux_map
{
	char	**map;
	int		count_e;
	int		count_c;
}	t_aux_map;

int		ft_count_file(char *file);
char	**ft_init_map(char *file);
void	count_size(t_mlx_data *data);
int		test_name(char *str, char *map_ext);
void	free_map(char **map);
int		close_all(t_mlx_data *data);
void	errmap_ex(t_mlx_data *data);
void	content_review(t_mlx_data *data);
void	check_content(t_mlx_data *data);
void	init_assets(t_mlx_data *data);
int		init_screen(t_mlx_data *data);
void	player_move(t_mlx_data *data, int y, int x);
int		check_path(t_mlx_data *data);

#endif
