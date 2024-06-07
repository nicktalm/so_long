/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:24:58 by ntalmon           #+#    #+#             */
/*   Updated: 2023/12/14 11:35:41 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	check_map_path(char **map, t_point	size)
{
	t_point	position_p;
	char	**cpymap;
	int		e;
	int		c;
	int		p;

	e = 0;
	c = 0;
	p = 0;
	position_p = search_p(map);
	cpymap = dupmap(map, size);
	fill(cpymap, size, position_p);
	count_characters(cpymap, &e, &c, &p);
	freearray2 (cpymap);
	if (e > 0 || c > 0 || p > 0)
		error(3, map);
	return (1);
}

void	fill(char **map, t_point size, t_point position_p)
{
	if (position_p.y < 0 || position_p.y >= size.y
		|| position_p.x < 0 || position_p.x >= size.x
		|| map[position_p.y][position_p.x] == '1'
		|| map[position_p.y][position_p.x] == 'X'
		|| map[position_p.y][position_p.x] == 'F')
		return ;
	map[position_p.y][position_p.x] = 'F';
	fill(map, size, (t_point){position_p.x - 1, position_p.y});
	fill(map, size, (t_point){position_p.x + 1, position_p.y});
	fill(map, size, (t_point){position_p.x, position_p.y - 1});
	fill(map, size, (t_point){position_p.x, position_p.y + 1});
}

int	check_map_characters(char **map)
{
	int		e;
	int		c;
	int		p;
	t_point	size;

	e = 0;
	c = 0;
	p = 0;
	size = count_characters(map, &e, &c, &p);
	if (e != 1 || c == 0 || p != 1)
		return (error_characters(&e, &c, &p, map));
	if (e == 1 || c >= 1 || p == 1)
		check_map_path(map, size);
	return (0);
}

t_point	count_characters(char **map, int *e, int *c, int *p)
{
	t_point	size;

	size.x = 0;
	size.y = 0;
	while (map[size.y])
	{
		size.x = 0;
		while (map[size.y][size.x])
		{
			if (map[size.y][size.x] == 'E')
				(*e)++;
			else if (map[size.y][size.x] == 'C')
				(*c)++;
			else if (map[size.y][size.x] == 'P')
				(*p)++;
			size.x++;
		}
		size.y++;
	}
	return (size);
}
