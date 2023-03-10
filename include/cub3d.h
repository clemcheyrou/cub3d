/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccheyrou <ccheyrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:20:58 by ccheyrou          #+#    #+#             */
/*   Updated: 2023/03/10 14:12:37 by ccheyrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include "../Libft/libft.h"
# include "../srcs/get_next_line/get_next_line.h"

# define CHAR_TITLE		"Totally Spies!"
# define FILE_EXT		".cub"
# define MAP_CHAR		"10NSEW"
# define IMG_LENGTH		34
# define IMG_WIDTH		34
# define W_K			119
# define S_K			115
# define A_K			97
# define D_K			100
# define ESC			65307
# define ESC_K		65307

# define ERR_ENV		"Error\nUninitialized environment\n"
# define ERR_ARG		"Error\nWrong number of arguments\n"
# define ERR_RD			"Error\nOpen fonction error\n"
# define ERR_EXT		"Error\nWrong file extension (must be .cub)\n"
# define ERR_MAP		"Error\nThe map is incorrect\n"
# define ERR_DEF		"Error\nThe map elements are missing or incorrect\n"
# define ERR_DBL		"Error\nThe map elements are mentionned twice\n"
# define ERR_MALLOC		"Error\nMalloc error\n"

typedef enum s_direction
{
	N,
	S,
	E,
	W
}	t_direction;

typedef struct s_elem
{
	char *no_img;
	char *so_img;
	char *we_img;
	char *ea_img;
	int floor[3];
	int	cell[3];
	int	flag_floor;
	int	flag_cell;
} t_elem;

typedef struct s_map
{
	char				**map;
	int					player_nb;
	int					elem_nb;
	int					map_width;
	int					map_height;
	t_direction			direction;
	t_elem				elem;
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
	//t_game game;
	char	**file;
}	t_cub3d;

char	**get_file(char *av, t_cub3d *cub3d);
int		check_cub(char *av);
int 	check_file(t_cub3d *cub3d);


#endif 