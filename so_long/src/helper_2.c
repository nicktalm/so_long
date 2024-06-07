/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:17:13 by ntalmon           #+#    #+#             */
/*   Updated: 2023/12/14 13:05:32 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_z_instances(t_vars *data)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	while (data->image[S]->instances[i].z < data->image[P]->instances[0].z)
		i++;
	z = data->image[S]->instances[i].z + 1;
	data->image[P]->instances[0].z = z;
}

int	count_c(t_vars	*data)
{
	t_point	size;

	size.x = 0;
	size.y = 0;
	data->coll_nbr = 0;
	while (data->map[size.y])
	{
		size.x = 0;
		while (data->map[size.y][size.x])
		{
			if (data->map[size.y][size.x] == 'C')
				data->coll_nbr++;
			size.x++;
		}
		size.y++;
	}
	return (0);
}

void	freearray(char **cpymap)
{
	int	j;

	j = 0;
	while (cpymap[j])
	{
		free(cpymap[j]);
		j++;
	}
	free(cpymap);
	error(8, cpymap);
}

void	freearray2(char **cpymap)
{
	int	j;

	j = 0;
	while (cpymap[j])
	{
		free(cpymap[j]);
		j++;
	}
	free(cpymap);
}

int	count_column(t_vars *data)
{
	int	counter;

	counter = 0;
	while (data->map[counter])
		counter++;
	return (counter + 1);
}
