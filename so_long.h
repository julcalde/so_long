/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 21:27:57 by julcalde          #+#    #+#             */
/*   Updated: 2025/01/21 17:54:46 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"

typedef struct s_game
{
	mlx_t			*mlx;
	char			**map;
	char			**map_copy;
	int				row;
	int				column;
	int				path_x;
	int				path_y;
	int				count_player;
	int				count_collect;
	int				count_moves;
	int				count_exit;
	int				locate_player_x;
	int				locate_player_y;
	int				exit_level;
	mlx_texture_t	*tmp;
	mlx_image_t		*wall;
	mlx_image_t		*floor;
	mlx_image_t		*player;
	mlx_image_t		*collectible;
	mlx_image_t		*exit;
}	t_game;

// map.c
void	verify_map_elements(t_game *game);
void	read_map(char *argv, t_game *game);
void	check_valid_map(char **bermap, t_game *game);
void	free_map(t_game *game);

// map_utils.c
void	check_elements(t_game *game);
void	verify_ele_amount(t_game *game);
void	verify_map_rectangular(t_game *game);
void	player_pos(t_game *game, int *p_row, int *p_col);
void	verify_win_cond(t_game *game);

// utils.c
void	perror_exit(char *str);
void	verify_args(int argc, char *argv);
void	ft_flood_fill(t_game *game, int path_x, int path_y);
void	fill_map(t_game *game, int path_x, int path_y);
void	freeda(t_game *game);

// load_textures.c
void	load_textures(t_game *game);
void	load_player(mlx_t *mlx, int row, int column, t_game *game);
void	load_collectible(mlx_t *mlx, int row, int column, t_game *game);
void	load_exit(mlx_t *mlx, int row, int column, t_game *game);
void	load_map(mlx_t *mlx, t_game *game);

// key_hook.c
void	key_set(mlx_key_data_t paramkey, t_game *game);
void	go_up(t_game *game);
void	go_down(t_game *game);
void	go_left(t_game *game);
void	go_right(t_game *game);

// init_game.c
void	init_vars(t_game *game);
void	win_game(t_game *game);
void	load_floors_and_walls(mlx_t *mlx, t_game *game);

#endif