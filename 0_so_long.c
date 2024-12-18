/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_so_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:59:38 by julcalde          #+#    #+#             */
/*   Updated: 2024/12/18 16:07:33 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define WINDOW_WIDTH 1080
#define WINDOW_HEIGTH 720

void	cleanup(mlx_t *mlx)
{
	if (mlx)
		mlx_terminate(mlx);
}

mlx_texture_t	*load_texture(mlx_t *mlx, const char *path)
{
	mlx_texture_t	*texture;


	texture = mlx_load_png(path);
	if (!texture)
	{
		ft_printf("ERROR\nFailed to load texture from %s\n", path);
		mlx_terminate(mlx);
		exit(1);
	}
	return (texture);
}

int	main(int argc, char **argv)
{
	mlx_t			*mlx;
	char			*path;
	mlx_texture_t	*wall_texture;
	mlx_texture_t	*player_texture;

	if (argc != 2)
		return (ft_printf("Error\nUse: ./so_long <map_name>.ber\n"), 1);
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
		return (ft_printf("Error\nUse: .ber extention\n"), 1);
	path = ft_strjoin("./maps/", argv[1]);
	if (!path)
		return (ft_printf("Problem creating map from %s\n", path), 1);
	mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGTH, "2D game", 1);
	if (mlx == NULL)
		return (ft_printf("ERROR\nFailed to initialize MLX42.\n"), 1);
	mlx_loop(mlx);
	wall_texture = load_texture(mlx, <wall_texture_path>);
	player_texture = load_texture(mlx, <player_texture_path>);
	mlx_delete_texture(wall_texture);
	mlx_delete_texture(player_texture);
	cleanup(mlx);
	return (0);
}
