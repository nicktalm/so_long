/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:41:10 by ntalmon           #+#    #+#             */
/*   Updated: 2023/12/12 17:00:20 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <fcntl.h>

char	**start(int argc, char **argv)
{
	char	**map;

	map = NULL;
	if (argc == 2)
	{
		if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
			error2(4);
		map = create_map(argv);
		check_map(map);
	}
	else
		error2(5);
	return (map);
}

char	**create_map(char **argv)
{
	char	**map;
	int		rows;
	int		fd;
	int		j;

	j = 0;
	rows = 0;
	fd = open(argv[1], O_RDONLY);
	rows = count_rows(fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	map = malloc(sizeof(char *) * (rows + 1));
	while (rows > j)
	{
		map[j] = get_next_line(fd);
		j++;
	}
	map[j] = NULL;
	close(fd);
	if (rows <= 2)
		error(7, map);
	return (map);
}

int	check_map(char **map)
{
	check_map_valid_char(map);
	check_map_rectangular(map);
	check_map_surrounded(map);
	check_map_characters(map);
	return (1);
}
