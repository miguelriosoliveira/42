/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-es <mrios-es@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:17:58 by mrios-es          #+#    #+#             */
/*   Updated: 2024/08/18 17:48:25 by mrios-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <mlx.h>
# include <X11/X.h>

# define PLAYER_FRONT_SPRITE "./assets/player/front1.xpm"
# define PLAYER_BACK_SPRITE "./assets/player/back1.xpm"
# define PLAYER_LEFT_SPRITE "./assets/player/left1.xpm"
# define PLAYER_RIGHT_SPRITE "./assets/player/right1.xpm"

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

typedef struct	s_player {
	int			x;
	int			y;
	t_sprite	front;
	t_sprite	back;
	t_sprite	left;
	t_sprite	right;
}				t_player;

typedef struct	s_vars {
	void		*mlx;
	void		*win;
	t_player	player;
}				t_vars;

#endif
