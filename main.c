/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 21:36:55 by julcalde          #+#    #+#             */
/*   Updated: 2025/01/19 21:14:56 by julcalde         ###   ########.fr       */
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
	mlx_key_hook(game->mlx, (mlx_keyfunc)key_set, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	freeda(game);
	return (0);
}
