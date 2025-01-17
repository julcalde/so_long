/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 21:27:57 by julcalde          #+#    #+#             */
/*   Updated: 2025/01/17 19:05:21 by julcalde         ###   ########.fr       */
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

void	perror_exit(char *str);
void	verify_args(int argc, char *argv);
void	read_map(char *argv, t_game *game);
void	verify_map_elements(t_game *game);
void	init_vars(t_game *game);
void	check_valid_map(char **bermap, t_game *game);
void	check_elements(t_game *game);
void	verify_ele_amount(t_game *game);
void	verify_map_rectangular(t_game *game);
void	player_pos(t_game *game, int p_row, int p_col);
void	verify_win_cond(t_game *game);
void	ft_flood_fill(t_game *game, int path_x, int path_y);
void	fill_map(t_game *game, int path_x, int path_y);

#endif