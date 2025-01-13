/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 21:36:55 by julcalde          #+#    #+#             */
/*   Updated: 2025/01/13 17:33:32 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t	main(int argc, char **argv)
{
	t_game	*game;

	verify_args(argc, argv[1]);
	game = malloc(sizeof(t_game));
	if (!game)
		return (ft_printf("Error\nFailed to allocate memory\n"), 1);
	read_map(argv[1], game);
	verify_map_elements(game);
	return (0);
}

void	verify_args(int argc, char **argv)
{
	if (argc != 2)
	{
		perror_exit("Use: ./so_long [map.ber]\n");
	}
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
	{
		perror_exit("Use: [file] with [.ber] extention\n");
	}
}

