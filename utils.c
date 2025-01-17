/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:17:48 by julcalde          #+#    #+#             */
/*   Updated: 2025/01/17 19:00:11 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	perror_exit(char *str)
{
	ft_printf("Error\n");
	ft_printf("%S", str);
	exit(EXIT_FAILURE);
}

void	verify_args(int argc, char *argv)
{
	if (argc != 2)
	{
		perror_exit("Use: ./so_long [map.ber]\n");
	}
	if (ft_strnstr(&argv[1], ".ber", ft_strlen(&argv[1])) == NULL)
	{
		perror_exit("Use: [file] with [.ber] extention\n");
	}
}

void	ft_flood_fill(t_game *game, int path_x, int path_y)
{
	if (path_x < 0 || path_y < 0 || path_x >= game->column || \
		path_y >= game->row || game->map_copy[path_x][path_y] == '1' || \
		game->map_copy[path_x][path_y] == 'V')
		return ;
	if (((game->map_copy[path_x + 1][path_y] == 'E') || \
		(game->map_copy[path_x - 1][path_y] == 'E')) && \
		((game->map_copy[path_x][path_y + 1] == '1') || \
		(game->map_copy[path_x][path_y + 1] == '1')))
		return ;
	if (((game->map_copy[path_x][path_y + 1] == 'E') || \
		(game->map_copy[path_x][path_y - 1] == 'E')) && \
		((game->map_copy[path_x + 1][path_y] == '1') || \
		(game->map_copy[path_x - 1][path_y] == '1')))
		return ;
	if (game->map_copy[path_x][path_y] == 'E' || \
		game->map_copy[path_x][path_y] == 'C')
		game->map_copy[path_x][path_y] = '0';
	game->map_copy[path_x][path_y] = 'V';
	ft_flood_fill(game, path_x + 1, path_y);
	ft_flood_fill(game, path_x - 1, path_y);
	ft_flood_fill(game, path_x, path_y + 1);
	ft_flood_fill(game, path_x, path_y - 1);
}

void	fill_map(t_game *game, int path_x, int path_y)
{
	ft_flood_fill(game, path_x, path_y);
}
