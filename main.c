/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 21:36:55 by julcalde          #+#    #+#             */
/*   Updated: 2025/01/12 22:48:02 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t	main(int argc, char **argv)
{
	t_game	*game;

	verify_argc(argc, argv);
	game = malloc(sizeof(t_game));
	if (!game)
		return (ft_printf("Error\nFailed to allocate memory\n"), 1);
	
	return (0);
}

void	verify_args(int argc, char **argv)
{
	if (argc != 2)
	{
		return (ft_printf("Error\nUse: ./so_long [map.ber]\n"), 1);
	}
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
	{
		return (ft_printf("Error\nUse: [file] with [.ber] extention\n"), 1);
	}
}
