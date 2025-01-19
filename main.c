/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 21:36:55 by julcalde          #+#    #+#             */
/*   Updated: 2025/01/19 17:44:43 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	verify_args(argc, argv[1]);
	game = malloc(sizeof(t_game));
	if (!game)
		return (ft_printf("Error\nFailed to allocate memory\n"), 1);
	read_map(argv[1], game);
	verify_map_elements(game);
	init_vars(game);
	check_valid_map(game->map, game);
	game->mlx = mlx_init(game->row * 32, game->column * 32, "Fish-cat", 0);
	load_map(game->mlx, game);
// set key hooks
// loop the game
// set termination of mlx42
// clean up and exit program
	return (0);
}
