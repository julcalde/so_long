/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:50:53 by julcalde          #+#    #+#             */
/*   Updated: 2024/12/17 22:05:43 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <math.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include "libft/include/printf/ft_printf.h"

typedef struct s_game
{
	char	**map;
	char	**map_copy;
	mlx_t	*mlx;
	int		win_width;
	int		win_height;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		moves;
}			t_game;


#endif