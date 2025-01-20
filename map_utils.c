/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:10:34 by julcalde          #+#    #+#             */
/*   Updated: 2025/01/20 22:26:40 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Utils to check map validity
	To add in function check_valid_map:
	
	//must check allowed elements in map: DONE
	//must check amount of P E & C: DONE
	//must check if the map is rectangular: DONE
	//must check if exit is accessible: 
	// ADD to map.c: 
*/
void	check_elements(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == 'P')
				game->count_player++;
			if (game->map[x][y] == 'C')
				game->count_collect++;
			if (game->map[x][y] == 'E')
				game->count_exit++;
			y++;
		}
		x++;
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
		if (line_len != tmp)
		{
			free_map(game);
			perror_exit("Map is not rectangular\n");
		}
		i++;
	}
	game->row = tmp;
}

void	player_pos(t_game *game, int *p_row, int *p_col)
{
	int	i;
	int	j;

	i = 0;
	while (game->map_copy[i])
	{
		j = 0;
		while (game->map_copy[i][j])
		{
			if (game->map_copy[i][j] == 'P')
			{
				*p_row = i;
				*p_col = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	verify_win_cond(t_game *game)
{
	int	p_row;
	int	p_col;
	int	scan_row;
	int	scan_col;

	p_row = 0;
	p_col = 0;
	scan_row = 0;
	player_pos(game, &p_row, &p_col);
	fill_map(game, p_row, p_col);
	while (game->map_copy[scan_row])
	{
		scan_col = 0;
		ft_printf("scan row %d\n", scan_row);
		while (game->map_copy[scan_row][scan_col])
		{
			if (game->map_copy[scan_row][scan_col] == 'C' || \
				game->map_copy[scan_row][scan_col] == 'E')
				perror_exit("Win is not an option\n");
			ft_printf("scan col %d\n", scan_col);
			scan_col++;
		}
		scan_row++;
	}
}
