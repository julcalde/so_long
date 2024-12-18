/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_so_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:41:14 by julcalde          #+#    #+#             */
/*   Updated: 2024/12/18 17:40:04 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	*path;

	if (argc != 2)
		return (ft_printf("Error\nUse: ./so_long/<map_name.ber>\n"), 1);
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
		return (ft_printf("Error\nMap file must have .ber extention.\n"), 1);
	path = ft_strjoin("./maps/", argv[1]);
	if (path == NULL)
	{
		ft_printf("Error\nFailed to allocate memory for map path.\n");
		return (1);
	}
	if (load_map(path) != 0)
	{
		ft_printf("Error:\nFailed to load map from %s\n", path);
		free(path);
		return (1);
	}
	free(path);
	return (0);
}

int	load_map(const char *path)
{
	int		fd;
	char	*line;
	char	**map;
	int		line_count;
	char	**temp;

	map = NULL;
	line_count = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error\nFailed to open file: %s\n", path), 1);
	while ((line = get_next_line(fd)) != NULL)
	{
		temp = (char **)malloc(sizeof(char *) * (line_count + 2));
		if (!temp)
		{
			ft_printf("Error\nMemory allocation failed for map lines.\n");
			free(line);
			break ;
		}
	}
}
