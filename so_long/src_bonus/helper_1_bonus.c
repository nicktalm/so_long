/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:43:29 by ntalmon           #+#    #+#             */
/*   Updated: 2023/12/14 11:36:02 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

char	**dupmap(char **map, t_point size)
{
	char	**cpymap;
	int		i;
	int		j;

	i = 0;
	j = 0;
	cpymap = (char **)malloc((size.y + 1) * sizeof(char *));
	if (cpymap == NULL)
		return (NULL);
	while (map[j] != NULL)
	{
		cpymap[j] = (char *)malloc((size.x + 1) * sizeof(char));
		if (!(cpymap[j]))
			freearray(cpymap);
		i = 0;
		while (map[j][i] && map[j][i] != '\n')
		{
			cpymap[j][i] = map[j][i];
			i++;
		}
		cpymap[j][i] = '\0';
		j++;
	}
	cpymap[j] = NULL;
	return (cpymap);
}

t_point	search_p(char **map)
{
	t_point	position_p;

	position_p.x = 0;
	position_p.y = 0;
	while (map[position_p.y])
	{
		while (map[position_p.y][position_p.x])
		{
			if (map[position_p.y][position_p.x] == 'P')
				return (position_p);
			position_p.x++;
		}
		position_p.y++;
		position_p.x = 0;
	}
	return (position_p);
}

int	count_rows(int fd)
{
	int		counter;
	char	*buffer;
	int		i;
	int		byte_size;

	counter = 0;
	i = 0;
	byte_size = 1;
	buffer = malloc(sizeof(char) * (10 + 1));
	if (buffer == NULL)
		return (0);
	while (byte_size != 0)
	{
		byte_size = read(fd, buffer, 10);
		if (byte_size == -1)
		{
			free (buffer);
			return (0);
		}
		buffer[byte_size] = '\0';
		i = 0;
		counter = count_rows_2(buffer, counter, i);
	}
	free(buffer);
	return (counter + 1);
}

int	count_rows_2(char *buffer, int counter, int i)
{
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			counter++;
		i++;
	}
	return (counter);
}

t_point	count_size_map(char **map)
{
	t_point	size;

	size.y = 0;
	while (map[size.y])
	{
		size.x = 0;
		while (map[size.y][size.x])
			size.x++;
		size.y++;
	}
	return (size);
}
