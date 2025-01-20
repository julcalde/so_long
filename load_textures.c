/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 21:59:58 by julcalde          #+#    #+#             */
/*   Updated: 2025/01/20 19:31:22 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_textures(t_game *game)
{
	game->tmp = mlx_load_png("textures/wall.png");
	game->wall = mlx_texture_to_image(game->mlx, game->tmp);
	mlx_delete_texture(game->tmp);
	game->tmp = mlx_load_png("textures/floor.png");
	game->floor = mlx_texture_to_image(game->mlx, game->tmp);
	mlx_delete_texture(game->tmp);
	game->tmp = mlx_load_png("textures/exit.png");
	game->exit = mlx_texture_to_image(game->mlx, game->tmp);
	mlx_delete_texture(game->tmp);
	game->tmp = mlx_load_png("textures/player.png");
	game->player = mlx_texture_to_image(game->mlx, game->tmp);
	mlx_delete_texture(game->tmp);
	game->tmp = mlx_load_png("textures/collectible.png");
	game->collectible = mlx_texture_to_image(game->mlx, game->tmp);
	mlx_delete_texture(game->tmp);
}

void	load_player(mlx_t *mlx, int row, int column, t_game *game)
{
	mlx_image_to_window(mlx, game->floor, column * 32, row * 32);
	mlx_image_to_window(mlx, game->player, column * 32, row * 32);
	game->path_x = row;
	game->path_y = column;
}

void	load_collectible(mlx_t *mlx, int row, int column, t_game *game)
{
	mlx_image_to_window(mlx, game->floor, column * 32, row * 32);
	mlx_image_to_window(mlx, game->collectible, column * 32, row * 32);
}

void	load_exit(mlx_t *mlx, int row, int column, t_game *game)
{
	mlx_image_to_window(mlx, game->floor, column * 32, row * 32);
	mlx_image_to_window(mlx, game->exit, column * 32, row * 32);
}

void	load_map(mlx_t *mlx, t_game *game)
{
	int	i;
	int	j;

	load_textures(game);
	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == '1')
			{
				// ft_printf("WALL I AM IN WALLS\n");
				mlx_image_to_window(mlx, game->wall, j * 32, i * 32);
			}
			else if (game->map[i][j] == 'C')
			{
				// ft_printf("before Collectible\n");
				load_collectible(mlx, i, j, game);
			}
			else if (game->map[i][j] == 'P')
			{
				// ft_printf("before player\n");
				load_player(mlx, i, j, game);
			}
			else if (game->map[i][j] == 'E')
			{
				// ft_printf("before Exit\n");
				load_exit(mlx, i, j, game);
			}
			else if (game->map[i][j] == '0')
			{
				// ft_printf("before floor\n");
				mlx_image_to_window(mlx, game->floor, j * 32, i * 32);
			}
		}
	}
}
