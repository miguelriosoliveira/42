/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:17:58 by mrios-es          #+#    #+#             */
/*   Updated: 2024/09/27 23:15:01 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <X11/X.h>
# include <mlx.h>
# include "../libft/libft.h"

# define SPRITE_PLAYER_UP "./assets/player/semi_up.xpm"
# define SPRITE_PLAYER_DOWN "./assets/player/semi_down.xpm"
# define SPRITE_PLAYER_LEFT "./assets/player/semi_left.xpm"
# define SPRITE_PLAYER_RIGHT "./assets/player/semi_right.xpm"

# define SPRITE_WALL "./assets/map/wall.xpm"
# define SPRITE_COLLECTABLE "./assets/map/collectable.xpm"
# define SPRITE_EXIT "./assets/map/exit.xpm"

# define MAP_WALL '1'
# define MAP_GROUND '0'
# define MAP_PLAYER 'P'
# define MAP_COLLECTIBLE 'C'
# define MAP_EXIT 'E'

# define TILE_SIZE 32

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define ARROW_UP 65362
# define ARROW_LEFT 65361
# define ARROW_DOWN 65364
# define ARROW_RIGHT 65363

# define DIR_UP 1
# define DIR_LEFT 2
# define DIR_DOWN 3
# define DIR_RIGHT 4

typedef struct	s_sprite {
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_sprite;

typedef struct	s_sprites {
	t_sprite	wall;
	t_sprite	exit;
	t_sprite	collectable;
	t_sprite	player_up;
	t_sprite	player_down;
	t_sprite	player_left;
	t_sprite	player_right;
}				t_sprites;

typedef struct	s_map {
	char		**content;
	int			width;
	int			height;
	int			collectable_count;
}				t_map;

typedef struct	s_player {
	int			x;
	int			y;
	int			n_steps;
}				t_player;

typedef struct	s_vars {
	void		*mlx;
	void		*win;
	t_sprites	sprites;
	t_map		map;
	t_player	player;
}				t_vars;

// hooks.c
int 	on_destroy(t_vars *vars);
int 	on_keypress(int keycode, t_vars *vars);

// render.c
void	render_map_part(t_vars *vars, t_sprite *sprite, int x, int y);
void	render_wall(t_vars *vars, int x, int y);
void	render_collectable(t_vars *vars, int x, int y);
void	render_exit(t_vars *vars, int x, int y);
void	render_map(t_vars *vars);
void	render_player(t_vars *vars, t_sprite *sprite);
void	render(t_vars *vars, t_sprite *player_sprite);

// so_long.c
void	print_vars(t_vars *vars);

// sprites.c
int		load_sprite(void *mlx, t_sprite *sprite_part, char *sprite_file);
int		load_sprites(t_vars *vars);

// validate.c
int		validate_map(char *filename, t_vars *vars);
int		validate_map_dimensions(t_vars *vars, char *filename);
int		validate_map_surrounded(t_vars *vars);
char	**clone_matrix(char **matrix, int width, int height);
int		has_valid_path(t_vars *vars, char **map, int *collectable_count, int x1, int y1);
int		validate_path(t_vars *vars);

#endif
