/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:20:58 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/03/08 16:45:45 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include "../Libft/libft.h"

# define CHAR_TITLE		"Totally Spies!"
# define FILE_EXT		".cub"
# define MAP_CHAR		"10NSEW"
# define IMG_LENGTH		34
# define IMG_WIDTH		34
# define W				119
# define S				115
# define A				97
# define D				100
# define ESC			65307


# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include "../minilibx/mlx.h"
# include "../Libft/libft.h"
# include <stdio.h>
# include <math.h>


typedef enum s_direction
{
	N,
	S,
	E,
	W
}	t_direction;

typedef struct s_texture
{
	char *no_img;
	char *so_img;
	char *we_img;
	char *ea_img;
} t_texture;

typedef struct s_color
{
	int *floor;
	int	*cell;
} t_color;

typedef struct s_map
{
	char				**map;
	int					player_nb;
	int					map_width;
	int					map_height;
	t_direction			direction;
	t_texture			texture;
	t
	
}	t_map;

// typedef struct s_game
// {
// 	void	*mlx;
// 	void *no_img;
// 	void *so_img;
// 	void *we_img;
// 	void *ea_img;
// }	t_game;

typedef struct s_cub3d
{
	t_map	map;
	t_game	game;
} 

#endif 