/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 22:04:13 by julcalde          #+#    #+#             */
/*   Updated: 2025/01/19 21:11:15 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	verify_map_elements(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (ft_strchr("01PCE", game->map[y][x]) == NULL)
			{
				free(game);
				perror_exit("Invalid elements in map\n");
				ft_printf("Allowed elements: P, C, E, 1, 0.\n");
			}
			x++;
		}
		y++;
	}
}

void	read_map(char *argv, t_game *game)
{
	int		fd;
	char	*tmp_catch_line;
	char	*total_map;
	char	*line;

	fd = open(argv, O_RDONLY);
	total_map = ft_strdup("");
	if (fd == -1)
		perror_exit("Failed to open file or file is empty\n");
	line = get_next_line(fd);
	if (!line)
		perror_exit("File is empty\n");
	while (line)
	{
		tmp_catch_line = ft_strjoin(total_map, line);
		free(total_map);
		total_map = tmp_catch_line;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	free(tmp_catch_line);
	close(fd);
	game->map = ft_split(total_map, '\n');
	game->map_copy = ft_split(total_map, '\n');
}

void	check_valid_map(char **bermap, t_game *game)
{
	int	i;
	int	j;

	while (bermap[game->row])
	{
		while (bermap[game->row][game->column])
			game->column++;
		game->row++;
	}
	i = -1;
	while (bermap[i])
	{
		j = -1;
		while (bermap[i][++j])
		{
			if ((i == 0 || i == game->row -1) || \
			(j == 0 || j == game->column - 1))
				if (bermap[i][j] != '1')
					perror_exit("Map is not enclosed by walls\n");
		}
	}
	check_elements(game);
	verify_ele_amount(game);
	verify_map_rectangular(game);
	verify_win_cond(game);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->row)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	game->map = NULL;
}
