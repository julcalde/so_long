/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:07:42 by julcalde          #+#    #+#             */
/*   Updated: 2025/01/19 21:02:53 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_set(mlx_key_data_t paramkey, t_game *game)
{
	if (paramkey.key == MLX_KEY_W && paramkey.action == MLX_RELEASE)
		go_up(game);
	if (paramkey.key == MLX_KEY_S && paramkey.action == MLX_RELEASE)
		go_down(game);
	if (paramkey.key == MLX_KEY_A && paramkey.action == MLX_RELEASE)
		go_left(game);
	if (paramkey.key == MLX_KEY_D && paramkey.action == MLX_RELEASE)
		go_right(game);
	if (paramkey.key == MLX_KEY_ESCAPE && paramkey.action == MLX_RELEASE)
		freeda(game);
}

void	go_up(t_game *game)
{
	if (game->map[game->path_x - 1][game->path_y] != '1' && \
		(game->map[game->path_x - 1][game->path_y] != 'E' || \
		game->count_collect == 0))
	{
		game->map[game->path_x][game->path_y] = 0;
		if (game->map[game->path_x - 1][game->path_y] == 'C')
		{
			game->count_collect -= 1;
		}
		if (game->map[game->path_x - 1][game->path_y] == 'E' && \
			game->count_collect == 0)
			win_game(game);
		else
		{
			game->map[game->path_x - 1][game->path_y] = 'P';
			load_map(game->mlx, game);
			game->count_moves += 1;
			ft_printf("%d", game->count_moves);
		}
	}
}

void	go_down(t_game *game)
{
	if (game->map[game->path_x + 1][game->path_y] != '1' && \
		(game->map[game->path_x + 1][game->path_y] != 'E' || \
		game->count_collect == 0))
	{
		game->map[game->path_x][game->path_y] = 0;
		if (game->map[game->path_x + 1][game->path_y] == 'C')
		{
			game->count_collect -= 1;
		}
		if (game->map[game->path_x + 1][game->path_y] == 'E' && \
			game->count_collect == 0)
			win_game(game);
		else
		{
			game->map[game->path_x + 1][game->path_y] = 'P';
			load_map(game->mlx, game);
			game->count_moves += 1;
			ft_printf("%d", game->count_moves);
		}
	}
}

void	go_left(t_game *game)
{
	if (game->map[game->path_x][game->path_y - 1] != '1' && \
		(game->map[game->path_x][game->path_y - 1] != 'E' || \
		game->count_collect == 0))
	{
		game->map[game->path_x][game->path_y] = 0;
		if (game->map[game->path_x][game->path_y - 1] == 'C')
		{
			game->count_collect -= 1;
		}
		if (game->map[game->path_x][game->path_y - 1] == 'E' && \
			game->count_collect == 0)
			win_game(game);
		else
		{
			game->map[game->path_x][game->path_y - 1] = 'P';
			load_map(game->mlx, game);
			game->count_moves += 1;
			ft_printf("%d", game->count_moves);
		}
	}
}

void	go_right(t_game *game)
{
	if (game->map[game->path_x][game->path_y + 1] != '1' && \
		(game->map[game->path_x][game->path_y + 1] != 'E' || \
		game->count_collect == 0))
	{
		game->map[game->path_x][game->path_y] = 0;
		if (game->map[game->path_x][game->path_y + 1] == 'C')
		{
			game->count_collect -= 1;
		}
		if (game->map[game->path_x][game->path_y + 1] == 'E' && \
			game->count_collect == 0)
			win_game(game);
		else
		{
			game->map[game->path_x][game->path_y + 1] = 'P';
			load_map(game->mlx, game);
			game->count_moves += 1;
			ft_printf("%d", game->count_moves);
		}
	}
}
