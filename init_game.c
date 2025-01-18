/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:21:58 by julcalde          #+#    #+#             */
/*   Updated: 2025/01/18 17:18:14 by julcalde         ###   ########.fr       */
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


