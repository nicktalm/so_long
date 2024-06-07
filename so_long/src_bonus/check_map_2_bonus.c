/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:32:13 by ntalmon           #+#    #+#             */
/*   Updated: 2023/12/14 11:35:45 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	get_string_length(const char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0' && str[length] != '\n')
	{
		length++;
	}
	return (length);
}

int	check_all_row_lengths(char **map, int first_row_length)
{
	int	i;
	int	current_row;

	i = 0;
	current_row = 0;
	while (map[i] != NULL)
	{
		current_row = get_string_length(map[i]) - 1;
		if (current_row != first_row_length)
			error(1, map);
		i++;
	}
	return (1);
}

int	check_map_rectangular(char **map)
{
	int	first_row_length;

	if (map == NULL || map[0] == NULL)
	{
		return (0);
	}
	first_row_length = get_string_length(map[0]) - 1;
	return (check_all_row_lengths(map, first_row_length));
}

int	check_map_surrounded(char **map)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (map[j] != NULL)
	{
		if (map[j][0] != '1' || map[j][get_string_length(map[j]) - 1] != '1')
			error(2, map);
		j++;
	}
	while (map[0][i] != '\n' && map[0][i] != '\0')
	{
		if (map[0][i++] != '1')
			error(2, map);
	}
	i = 0;
	j = j - 1;
	while (map[j][i] != '\n' && map[j][i] != '\0')
	{
		if (map[j][i++] != '1')
			error(2, map);
	}
	return (1);
}

int	check_map_valid_char(char **map)
{
	t_point	size;

	size.x = 0;
	size.y = 0;
	while (map[size.y])
	{
		size.x = 0;
		while (map[size.y][size.x])
		{
			if (map[size.y][size.x] != '0' && map[size.y][size.x] != '1'
				&& map[size.y][size.x] != 'E' && map[size.y][size.x] != 'C'
				&& map[size.y][size.x] != 'P' && map[size.y][size.x] != 'X'
				&& map[size.y][size.x] != '\n')
				error(6, map);
			size.x++;
		}
		size.y++;
	}
	return (0);
}
