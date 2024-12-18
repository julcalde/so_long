/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:50:12 by julcalde          #+#    #+#             */
/*   Updated: 2024/12/18 14:40:46 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(mlx_t *mlx, char **map, mlx_texture_t *wall_texture, \
mlx_texture_t *player_texture)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
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
