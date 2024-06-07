/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:58:57 by ntalmon           #+#    #+#             */
/*   Updated: 2023/12/14 11:35:52 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	exit_and_collectible(t_vars *data)
{
	data->steps++;
	display_in_window(data);
	ft_printf("move: %d\n", data->steps);
	if (data->map[data->p_h][data->p_w] == 'E')
	{
		if (data->coll_nbr == 0)
		{
			you_win(data);
		}
	}
	if (data->map[data->p_h][data->p_w] == 'X')
		you_died(data);
	if (data->map[data->p_h][data->p_w] == 'C')
	{
		mlx_image_to_window(data->mlx, data->image[S],
			data->p_w * 32, data->p_h * 32);
		data->map[data->p_h][data->p_w] = '0';
		check_z_instances(data);
	}
}

void	display_in_window(t_vars *data)
{
	char	*moves;

	moves = ft_itoa(data->steps);
	mlx_image_to_window(data->mlx, data->image[W], 128, 0);
	mlx_image_to_window(data->mlx, data->image[W], 160, 0);
	mlx_put_string(data->mlx, moves, 138, 0);
	free (moves);
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
