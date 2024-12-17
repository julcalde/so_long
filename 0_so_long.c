/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_so_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:59:38 by julcalde          #+#    #+#             */
/*   Updated: 2024/12/17 22:30:41 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define WINDOW_WIDTH 1080
#define WINDOW_HEIGTH 720

void	cleanup(mlx_t *mlx)
{
	if (mlx)
		mlx_terminate(mlx);
}

mlx_texture_t	*load_texture(mlx_t *mlx, const char *path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
	{
		ft_printf("ERROR\nFailed to load texture from %s\n", path);
		mlx_terminate(mlx);
		exit(1);
	}
	return (texture);
}

void	render_map(mlx_t *mlx, char **map, mlx_texture_t *wall_texture, mlx_texture_t *player_texture);
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == '1')
				mlx_draw_texture(mlx, wall_texture, x * 32, y * 32);
			else if (map[y][x] == 'P')
				mlx_draw_texture(mlx, player_texture, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	mlx_t	*mlx;

	mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGTH , "2D game", 1);
	if (!mlx)
	{
		ft_printf("ERROR\nFailed to initialize MLX42.\n");
		return (1);
	}
	// mlx_texture_t *wall_texture = load_texture(mlx, <wall texture path>)
	// mlx_texture_t *player_texture = load_texture(mlx, <player texture path>)
	mlx_loop(mlx);
	// mlx_delete_texture(wall_texture);
	// mlx_delete_texture(player_texture);
	cleanup(mlx);
	return (0);
}
