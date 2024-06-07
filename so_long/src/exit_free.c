/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:58:57 by ntalmon           #+#    #+#             */
/*   Updated: 2023/12/14 13:05:24 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	exit_and_collectible(t_vars *data)
{
	if (data->map[data->p_h][data->p_w] == 'E')
	{
		data->steps++;
		if (data->coll_nbr == 0)
		{
			mlx_close_window(data->mlx);
			ft_printf("\nCongrats, you won with %i moves!\n\n", data->steps);
			exit_and_free(data);
		}
	}
	if (data->map[data->p_h][data->p_w] == 'C')
	{
		mlx_image_to_window(data->mlx, data->image[S],
			data->p_w * 32, data->p_h * 32);
		data->map[data->p_h][data->p_w] = '0';
		check_z_instances(data);
	}
	data->steps++;
	ft_printf("move: %d\n", data->steps);
}

void	exit_and_free(t_vars *data)
{
	int		h;
	t_point	size;

	h = 0;
	size = count_size_map(data->map);
	while (h < size.y && data->map[h])
	{
		free(data->map[h]);
		h++;
	}
	free(data->map);
	h = 0;
	while (h < TEXTURES)
	{
		if (data->textures[h])
			mlx_delete_texture(data->textures[h]);
		h++;
	}
	mlx_terminate(data->mlx);
	exit (0);
}

void	free_map(char **map)
{
	int		h;

	h = 0;
	while (map[h])
	{
		free(map[h]);
		h++;
	}
	free(map);
}
