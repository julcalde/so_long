/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:10:34 by julcalde          #+#    #+#             */
/*   Updated: 2025/01/17 14:02:49 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Utils to check map validity
	To add in function check_valid_map:
	
	//must check allowed elements in map: DONE
	//must check amount of P E & C: DONE
	//must check if the map is rectangular: DONE
	//must check if exit is accessible: 
*/
void	check_elements(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
				game->count_player++;
			if (game->map[y][x] == 'C')
				game->count_collect++;
			if (game->map[y][x] == 'E')
				game->count_exit++;
			x++;
		}
		y++;
	}
}

void	verify_ele_amount(t_game *game)
{
	if (game->count_player != 1 || game->count_exit != 1)
	{
		free(game);
		perror_exit("Invalid amount of Players and/or Exits\n");
	}
	if (game->count_collect < 1)
	{
		perror_exit("Amount of Collectibles must be at least 1\n");
		free(game);
	}
}

void	verify_map_rectangular(t_game *game)
{
	int	i;
	int	line_len;
	int	tmp;

	game->row = 0;
	i = 0;
	tmp = 0;
	line_len = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		tmp = ft_strlen(game->map[i]);
		if (line_len != ft_strlen(game->map[i]))
		{
			free(game);
			perror_exit("Map is not rectangular\n");
		}
		i++;
	}
	game->row = tmp;
}
