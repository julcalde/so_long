/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:21:58 by julcalde          #+#    #+#             */
/*   Updated: 2025/01/21 17:54:37 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_vars(t_game *game)
{
	game->row = 0;
	game->column = 0;
	game->path_x = 0;
	game->path_x = 0;
	game->count_player = 0;
	game->count_collect = 0;
	game->count_moves = 0;
	game->count_exit = 0;
	game->count_moves = 0;
	game->locate_player_x = 0;
	game->locate_player_y = 0;
}

void	win_game(t_game *game)
{
	ft_printf("You finished the game!");
	freeda(game);
}

void	load_floors_and_walls(mlx_t *mlx, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			mlx_image_to_window(mlx, game->floor, j * 32, i * 32);
			if (game->map[i][j] == '1')
				mlx_image_to_window(mlx, game->wall, j * 32, i * 32);
		}
	}
}
