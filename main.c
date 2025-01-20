/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 21:36:55 by julcalde          #+#    #+#             */
/*   Updated: 2025/01/20 22:06:24 by julcalde         ###   ########.fr       */
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
	ft_printf("4: game row %d\n", game->row);
	ft_printf("game column %d\n", game->column);
	game->mlx = mlx_init(game->row * 32, game->column * 32, "Cat Fishing", 1);
	ft_printf("1 We are before loading map\n");
	load_map(game->mlx, game);
	ft_printf("2 Now the key hook\n");
	mlx_key_hook(game->mlx, (mlx_keyfunc)key_set, game);
	ft_printf("3 the loop\n");
	mlx_loop(game->mlx);
	ft_printf("4 termination\n");
	mlx_terminate(game->mlx);
	ft_printf("5 safe exit\n");
	freeda(game);
	ft_printf("6 game freed\n");
	return (0);
}
